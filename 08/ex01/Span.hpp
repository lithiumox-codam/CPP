#pragma once

#include <exception>
#include <vector>

class Span {
   private:
	std::vector<int> numbers;
	unsigned int maxSize;

   public:
	// no default constructor, as it is required to specify the size of the Span
	Span(unsigned int N);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	void addNumber(int number);

	template <typename Iterator>
	void addNumbers(Iterator begin, Iterator end);

	int shortestSpan() const;
	int longestSpan() const;

	class SpanFullException : public std::exception {
	   public:
		const char* what() const noexcept override;
	};

	class NoSpanException : public std::exception {
	   public:
		const char* what() const noexcept override;
	};
};

/**
 * @brief Implementation of addNumbers method that takes a range of iterators.
 * This method allows adding multiple numbers to the Span object from a range defined by two iterators.
 * It checks if the Span is full before adding each number, throwing an exception if it is.
 * @tparam Iterator
 * @param begin
 * @param end
 */
template <typename Iterator>
void Span::addNumbers(Iterator begin, Iterator end) {
	for (Iterator it = begin; it != end; ++it) {
		if (numbers.size() >= maxSize) {
			throw SpanFullException();
		}
		numbers.push_back(*it);
	}
}
