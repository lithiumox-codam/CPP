#include <chrono>
#include <iomanip>
#include <iostream>
#include <random>
#include <string>
#include <vector>

#include "Span.hpp"

void printHeader(const std::string& title) {
	std::cout << "\n" << std::string(50, '-') << "\n";
	std::cout << "  " << title << "\n";
	std::cout << std::string(50, '-') << "\n";
}

void printResult(const std::string& label, int value) {
	std::cout << std::setw(15) << std::left << label << ": " << value << "\n";
}

void testBasicFunctionality() {
	printHeader("Basic Functionality Test (Required Output)");

	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	printResult("Shortest span", sp.shortestSpan());
	printResult("Longest span", sp.longestSpan());
}

void testExceptions() {
	printHeader("Exception Tests");

	try {
		Span sp(3);
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
		sp.addNumber(4);
		std::cout << "ERROR: Should have thrown SpanFullException\n";
	} catch (const Span::SpanFullException& e) {
		std::cout << "PASSED: SpanFullException caught: " << e.what() << "\n";
	}

	try {
		Span sp(5);
		sp.addNumber(42);
		sp.shortestSpan();
		std::cout << "ERROR: Should have thrown NoSpanException\n";
	} catch (const Span::NoSpanException& e) {
		std::cout << "PASSED: NoSpanException caught: " << e.what() << "\n";
	}

	try {
		Span sp(0);
		sp.longestSpan();
		std::cout << "ERROR: Should have thrown NoSpanException\n";
	} catch (const Span::NoSpanException& e) {
		std::cout << "PASSED: NoSpanException caught for empty span: " << e.what() << "\n";
	}
}

void testIteratorRange() {
	printHeader("Iterator Range Test");

	std::vector<int> numbers = {1, 3, 6, 9, 11};
	Span sp(10);

	sp.addNumbers(numbers.begin(), numbers.end());

	std::cout << "Added numbers using iterator range\n";
	printResult("Shortest span", sp.shortestSpan());
	printResult("Longest span", sp.longestSpan());
}

void testLargeNumbers() {
	printHeader("Large Numbers Test (15,000 numbers)");

	auto start = std::chrono::high_resolution_clock::now();

	Span sp(15000);
	std::vector<int> numbers;
	numbers.reserve(15000);

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(-50000, 50000);

	for (int i = 0; i < 15000; ++i) {
		numbers.push_back(dis(gen));
	}

	sp.addNumbers(numbers.begin(), numbers.end());

	int shortest = sp.shortestSpan();
	int longest = sp.longestSpan();

	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

	std::cout << "Successfully processed 15,000 numbers\n";
	printResult("Shortest span", shortest);
	printResult("Longest span", longest);
	printResult("Time taken", duration.count());
	std::cout << " ms\n";
}

void testEdgeCases() {
	printHeader("Edge Cases Test");

	Span sp(5);
	sp.addNumber(-10);
	sp.addNumber(10);

	std::cout << "With negative and positive numbers:\n";
	printResult("Shortest span", sp.shortestSpan());
	printResult("Longest span", sp.longestSpan());

	std::cout << "\nWith duplicate numbers:\n";
	Span sp2(3);
	sp2.addNumber(100);
	sp2.addNumber(100);
	sp2.addNumber(200);

	printResult("Shortest span", sp2.shortestSpan());
	printResult("Longest span", sp2.longestSpan());
}

int main() {
	testBasicFunctionality();
	testExceptions();
	testIteratorRange();
	testLargeNumbers();
	testEdgeCases();

	return 0;
}