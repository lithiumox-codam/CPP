#include <chrono>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <limits>

#include "PmergeMe.hpp"

std::chrono::microseconds getCurrentTimeMicro() {
	return std::chrono::duration_cast<std::chrono::microseconds>(
		std::chrono::high_resolution_clock::now().time_since_epoch());
}

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
	std::cout << '\n';
}

int main(int argc, char** argv) {
	if (argc < 2) {
		std::cerr << "Error: No input sequence provided.\n";
		return 1;
	}

	std::vector<int> initial_sequence;
	for (int i = 1; i < argc; ++i) {
		char* end;
		long val = std::strtol(argv[i], &end, 10);
		if (*end != '\0') {
			std::cerr << "Error: Non-numeric input '" << argv[i] << "'\n";
			return 1;
		}
		if (val <= 0) {
			std::cerr << "Error: Negative or zero value '" << val << "'\n";
			return 1;
		}
		if (val > std::numeric_limits<int>::max()) {
			std::cerr << "Error: Value too large '" << val << "'\n";
			return 1;
		}
		initial_sequence.push_back(static_cast<int>(val));
	}

	std::vector<int> vec = initial_sequence;
	std::deque<int> deq = std::deque<int>(initial_sequence.begin(), initial_sequence.end());

	std::cout << "Before: ";
	printContainer(vec);

	auto start_vec = getCurrentTimeMicro();
	PmergeMe::sort(vec);
	auto end_vec = getCurrentTimeMicro();
	auto time_vec = end_vec - start_vec;

	auto start_deq = getCurrentTimeMicro();
	PmergeMe::sort(deq);
	auto end_deq = getCurrentTimeMicro();
	auto time_deq = end_deq - start_deq;

	std::cout << "After:  ";
	printContainer(vec);

	std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << time_vec.count()
			  << " us\n";
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque  : " << time_deq.count()
			  << " us\n";

	return 0;
}
