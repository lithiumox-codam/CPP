#pragma once

#include <sys/time.h>

#include <algorithm>
#include <utility>
#include <vector>

class PmergeMe {
   private:
	PmergeMe() = delete;
	PmergeMe(const PmergeMe& src) = delete;
	PmergeMe& operator=(const PmergeMe& rhs) = delete;
	~PmergeMe() = delete;

	/**
	 * 0, 1, 3, 5, 11, 21, 43, 85, 171, ...
	 * j(n) = j(n - 1) + 2 * j(n - 2)
	 */
	static void generateJacobsthal(std::vector<int>& jacob, int n) {
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
		// Base case for if the container is empty or has one element (already sorted)
		if (c.size() <= 1) return;

		// --- Step 1 & 2: Pair elements and sort pairs ---
		typedef std::pair<int, int> IntPair;
		std::vector<IntPair> pairs;
		int straggler = -1;

		size_t num_pairs = c.size() / 2;
		if (c.size() % 2 != 0) straggler = *c.rbegin();

		typename Container::iterator it = c.begin();
		for (size_t i = 0; i < num_pairs; ++i) {
			int first = *it;
			++it;
			int second = *it;
			++it;
			pairs.push_back(first < second ? std::make_pair(first, second) : std::make_pair(second, first));
		}

		// --- Step 3: Create main chain and pend elements ---
		Container main_chain;
		Container pend_elements;
		for (size_t i = 0; i < pairs.size(); ++i) {
			main_chain.push_back(pairs[i].second);
			pend_elements.push_back(pairs[i].first);
		}

		// Recursively sort the main chain
		sort(main_chain);

		// --- Step 4: Insert pend elements using Jacobsthal sequence ---
		// The first pend element is always inserted at the beginning
		if (!pend_elements.empty()) {
			main_chain.insert(main_chain.begin(), pend_elements[0]);
		}

		// Insert remaining pend elements using Jacobsthal sequence
		std::vector<int> jacob_indices;
		generateJacobsthal(jacob_indices, pend_elements.size());

		std::vector<bool> inserted(pend_elements.size(), false);
		inserted[0] = true;	 // First element already inserted

		for (size_t i = 2; i < jacob_indices.size(); ++i) {
			size_t current_jacob_idx = static_cast<size_t>(jacob_indices[i]);
			if (current_jacob_idx > pend_elements.size()) {
				current_jacob_idx = pend_elements.size();
			}

			// Insert elements from current_jacob_idx down to previous jacob index + 1
			size_t prev_jacob_idx = (i > 2) ? static_cast<size_t>(jacob_indices[i - 1]) : 1;
			for (size_t j = current_jacob_idx; j > prev_jacob_idx && j <= pend_elements.size(); --j) {
				if (!inserted[j - 1]) {
					int val_to_insert = pend_elements[j - 1];
					typename Container::iterator pos =
						std::lower_bound(main_chain.begin(), main_chain.end(), val_to_insert);
					main_chain.insert(pos, val_to_insert);
					inserted[j - 1] = true;
				}
			}
		}

		// Insert any remaining elements that weren't inserted by Jacobsthal sequence
		for (size_t i = 1; i < pend_elements.size(); ++i) {
			if (!inserted[i]) {
				int val_to_insert = pend_elements[i];
				typename Container::iterator pos =
					std::lower_bound(main_chain.begin(), main_chain.end(), val_to_insert);
				main_chain.insert(pos, val_to_insert);
			}
		}
		// --- Step 5: Insert the straggler ---
		if (straggler != -1) {
			typename Container::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), straggler);
			main_chain.insert(pos, straggler);
		}
		// --- Step 6: Assign the sorted main chain back to the original container ---
		c = main_chain;
	}
};