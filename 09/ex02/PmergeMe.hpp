#pragma once

#include <sys/time.h>

#include <algorithm>

class PmergeMe {
   private:
	PmergeMe() = default;
	PmergeMe(const PmergeMe& src) = default;
	PmergeMe& operator=(const PmergeMe& rhs) = default;
	~PmergeMe() = default;

	/**
	 * 0, 1, 3, 5, 11, 21, 43, 85, 171, ...
	 * j(n) = j(n - 1) + 2 * j(n - 2)
	 */
	template <typename Container>
	static void generateJacobsthal(Container& jacob, int n) {
		if (n <= 0) return;
		jacob.push_back(0);
		jacob.push_back(1);
		int last = 1, before_last = 0;
		while (true) {
			int next = last + 2 * before_last;
			if (next > n) break;
			before_last = last;
			last = next;
			jacob.push_back(last);
		}
	}

   public:
	template <typename Container>
	static void sort(Container& c) {
		if (c.size() <= 1) return;

		// --- Step 1 & 2: Pair elements and sort pairs ---
		Container pairs_flat;
		int straggler = -1;

		size_t num_pairs = c.size() / 2;
		if (c.size() % 2 != 0) straggler = *std::prev(c.end());

		typename Container::iterator it = c.begin();
		for (size_t i = 0; i < num_pairs; ++i) {
			int first = *it++;
			int second = *it++;

			if (first > second) std::swap(first, second);

			pairs_flat.push_back(first);
			pairs_flat.push_back(second);
		}

		// --- Step 3: Create main chain and pend elements ---
		Container main_chain;
		Container pend_elements;
		for (size_t i = 0; i < num_pairs; ++i) {
			pend_elements.push_back(pairs_flat[i * 2]);
			main_chain.push_back(pairs_flat[i * 2 + 1]);
		}

		sort(main_chain);

		// --- Step 4: Insert pend elements using Jacobsthal sequence ---

		// The first pend element is always inserted at the beginning
		if (!pend_elements.empty()) main_chain.insert(main_chain.begin(), pend_elements[0]);

		Container jacob_indices;
		generateJacobsthal(jacob_indices, pend_elements.size());

		Container inserted;
		for (size_t i = 0; i < pend_elements.size(); ++i) inserted.push_back(i == 0);

		// Insert pend elements at the indices specified by the Jacobsthal sequence
		for (size_t jacob_idx = 1; jacob_idx < jacob_indices.size(); ++jacob_idx) {
			size_t end_pos = std::min(static_cast<size_t>(jacob_indices[jacob_idx]), pend_elements.size());
			size_t start_pos = (jacob_idx == 1) ? 1 : static_cast<size_t>(jacob_indices[jacob_idx - 1]) + 1;

			for (size_t pos = end_pos; pos >= start_pos && pos <= pend_elements.size(); --pos) {
				if (!inserted[pos - 1]) {
					auto insert_pos = std::lower_bound(main_chain.begin(), main_chain.end(), pend_elements[pos - 1]);
					main_chain.insert(insert_pos, pend_elements[pos - 1]);
					inserted[pos - 1] = true;
				}
			}
		}

		// Insert any remaining pend elements that were not inserted by the Jacobsthal sequence
		for (size_t i = 1; i < pend_elements.size(); ++i) {
			if (!inserted[i]) {
				auto insert_pos = std::lower_bound(main_chain.begin(), main_chain.end(), pend_elements[i]);
				main_chain.insert(insert_pos, pend_elements[i]);
			}
		}

		// if there is a straggler, insert it at the correct position
		if (straggler != -1) {
			typename Container::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), straggler);
			main_chain.insert(pos, straggler);
		}

		c = main_chain;
	}
};