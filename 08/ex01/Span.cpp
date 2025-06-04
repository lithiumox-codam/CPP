#include "Span.hpp"

#include <algorithm>
#include <limits>

Span::Span(unsigned int N) : maxSize(N) { numbers.reserve(N); }

Span::Span(const Span& other) : numbers(other.numbers), maxSize(other.maxSize) {}

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		numbers = other.numbers;
		maxSize = other.maxSize;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
	if (numbers.size() >= maxSize) {
		throw SpanFullException();
	}
	numbers.push_back(number);
}

int Span::shortestSpan() const {
	if (numbers.size() < 2) {
		throw NoSpanException();
	}

	std::vector<int> sorted = numbers;
	std::sort(sorted.begin(), sorted.end());

	int minSpan = std::numeric_limits<int>::max();
	for (size_t i = 1; i < sorted.size(); ++i) {
		int span = sorted[i] - sorted[i - 1];
		if (span < minSpan) {
			minSpan = span;
		}
	}

	return minSpan;
}

int Span::longestSpan() const {
	if (numbers.size() < 2) {
		throw NoSpanException();
	}

	auto minmax = std::minmax_element(numbers.begin(), numbers.end());
	return *minmax.second - *minmax.first;
}

const char* Span::SpanFullException::what() const noexcept { return "Span is already full, cannot add more numbers"; }

const char* Span::NoSpanException::what() const noexcept { return "Cannot calculate span with less than 2 numbers"; }