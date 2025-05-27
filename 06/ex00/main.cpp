#include <cctype>
#include <cerrno>
#include <cfloat>
#include <cstdlib>
#include <iostream>
#include <string>

#include "ScalarConverter.hpp"

int main() {
	std::string input;
	std::cout << "Enter a literal: ";
	std::getline(std::cin, input);

	try {
		ScalarConverter::convert(input);
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}