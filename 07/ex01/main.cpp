#include <array>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "Iter.hpp"

// Function templates for printing with consistent formatting
void printInt(int &n) { std::cout << n << " "; }
void printConstInt(const int &n) { std::cout << n << " "; }
void printStr(std::string &s) { std::cout << s << " "; }
void printConstStr(const std::string &s) { std::cout << s << " "; }

// Modification function
void doubleInt(int &n) { n *= 2; }

// Helper function to print section headers
void printHeader(const std::string &header) {
	std::cout << "\n+" << std::string(50, '-') << "+" << std::endl;
	std::cout << "| " << std::left << std::setw(48) << header << " |" << std::endl;
	std::cout << "+" << std::string(50, '-') << "+" << std::endl;
}

int main(void) {
	printHeader("TESTING ITER WITH DIFFERENT CONTAINER TYPES");

	// Initialize test data
	int intArray[] = {1, 2, 3, 4, 5};
	const int constIntArray[] = {10, 20, 30, 40, 50};
	std::vector<int> intVec = {1, 2, 3, 4, 5};
	const std::vector<int> constIntVec = {10, 20, 30, 40, 50};
	std::array<int, 5> intStdArray = {1, 2, 3, 4, 5};
	const std::array<std::string, 3> constStrArray = {"Const", "String", "Array"};
	std::string strArray[] = {"Hello", "World", "!"};
	std::vector<std::string> strVec = {"Hello", "Vector", "World"};

	// C-style array tests
	printHeader("C-STYLE ARRAYS");
	std::cout << "• Regular int array:     ";
	::iter(intArray, 5, printInt);
	std::cout << std::endl;

	std::cout << "• Const int array:       ";
	::iter(constIntArray, 5, printConstInt);
	std::cout << std::endl;

	// Vector tests
	printHeader("VECTORS");
	std::cout << "• Int vector:            ";
	::iter(intVec.data(), intVec.size(), printInt);
	std::cout << std::endl;

	std::cout << "• Const int vector:      ";
	::iter(constIntVec.data(), constIntVec.size(), printConstInt);
	std::cout << std::endl;

	// std::array tests
	printHeader("STD::ARRAYS");
	std::cout << "• std::array<int>:       ";
	::iter(intStdArray.data(), intStdArray.size(), printInt);
	std::cout << std::endl;

	std::cout << "• Const std::array<str>: ";
	::iter(constStrArray.data(), constStrArray.size(), printConstStr);
	std::cout << std::endl;

	// String container tests
	printHeader("STRING CONTAINERS");
	std::cout << "• C-style string array:  ";
	::iter(strArray, 3, printStr);
	std::cout << std::endl;

	std::cout << "• String vector:         ";
	::iter(strVec.data(), strVec.size(), printStr);
	std::cout << std::endl;

	// Modification demonstration
	printHeader("MODIFYING DATA WITH ITER");
	std::cout << "• Before doubling:       ";
	::iter(intArray, 5, printInt);
	std::cout << std::endl;

	::iter(intArray, 5, doubleInt);

	std::cout << "• After doubling:        ";
	::iter(intArray, 5, printInt);
	std::cout << std::endl;

	return 0;
}