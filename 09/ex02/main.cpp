#include <cstdlib>
#include <deque>
#include <iostream>
#include <limits>

#include "PmergeMe.hpp"

long long getCurrentTimeMicro() {
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec * 1000000LL + tv.tv_usec;
}

// Helper to print a container (truncated for large containers)
template <typename Container>
void printContainer(const Container& c) {
	const size_t max_display = 10;

	if (c.size() <= max_display) {
		for (typename Container::const_iterator it = c.begin(); it != c.end(); ++it) {
			std::cout << *it << " ";
		}
	} else {
		typename Container::const_iterator it = c.begin();
		for (size_t i = 0; i < 5 && it != c.end(); ++i, ++it) {
			std::cout << *it << " ";
		}
		std::cout << "[...] ";

		typename Container::const_iterator end_it = c.end();
		std::advance(end_it, -5);
		for (; end_it != c.end(); ++end_it) {
			std::cout << *end_it << " ";
		}
	}
	std::cout << std::endl;
}

int main(int argc, char** argv) {
	if (argc < 2) {
		std::cerr << "Error: No input sequence provided." << std::endl;
		return 1;
	}

	std::vector<int> initial_sequence;
	for (int i = 1; i < argc; ++i) {
		char* end;
		long val = std::strtol(argv[i], &end, 10);
		if (*end != '\0') {
			std::cerr << "Error: Non-numeric input '" << argv[i] << "'" << std::endl;
			return 1;
		}
		if (val <= 0) {
			std::cerr << "Error: Negative or zero value '" << val << "'" << std::endl;
			return 1;
		}
		if (val > std::numeric_limits<int>::max()) {
			std::cerr << "Error: Value too large '" << val << "'" << std::endl;
			return 1;
		}
		initial_sequence.push_back(static_cast<int>(val));
	}

	// --- Prepare containers ---
	std::vector<int> vec = initial_sequence;
	std::deque<int> deq = std::deque<int>(initial_sequence.begin(), initial_sequence.end());

	// --- Print Before ---
	std::cout << "Before: ";
	printContainer(vec);

	// --- Time and sort std::vector ---
	long long start_vec = getCurrentTimeMicro();
	PmergeMe::sort(vec);
	long long end_vec = getCurrentTimeMicro();
	double time_vec = static_cast<double>(end_vec - start_vec);

	// --- Time and sort std::deque ---
	long long start_deq = getCurrentTimeMicro();
	PmergeMe::sort(deq);
	long long end_deq = getCurrentTimeMicro();
	double time_deq = static_cast<double>(end_deq - start_deq);

	// --- Print After and Timings ---
	std::cout << "After:  ";
	printContainer(vec);

	std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << time_vec << " us"
			  << std::endl;
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque  : " << time_deq << " us"
			  << std::endl;

	return 0;
}