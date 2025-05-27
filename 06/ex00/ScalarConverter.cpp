#include "ScalarConverter.hpp"

#include <cctype>
#include <cerrno>
#include <cfloat>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>

// Constructor
ScalarConverter::ScalarConverter() {}
// Copy constructor
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
// Assignment operator
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }
// Destructor
ScalarConverter::~ScalarConverter() {}
// Convert function
void ScalarConverter::convert(const std::string& literal) {
	Result result = parseLiteral(literal);
	printResult(result);
}
// Parse the literal
ScalarConverter::Result ScalarConverter::parseLiteral(const std::string& literal) {
	Result result;
	// Check for special cases: NaN, +inf, -inf
	if (literal == "nan" || literal == "nanf") {
		result.isNaN = true;
		return result;
	}
	if (literal == "+inf" || literal == "-inf" || literal == "inf" || literal == "+inff" || literal == "-inff" ||
		literal == "inff") {
		result.isInf = true;
		return result;
	}
	// Check for char
	if (literal.length() == 1 && std::isprint(literal[0])) {
		result.c = literal[0];
		result.hasChar = true;
		return result;
	}
	// Check for int
	try {
		long intValue = std::stol(literal);
		if (intValue < std::numeric_limits<int>::min() || intValue > std::numeric_limits<int>::max()) {
			throw std::out_of_range("Integer out of range");
		}
		result.i = static_cast<int>(intValue);
		result.hasInt = true;
	} catch (const std::invalid_argument&) {
	} catch (const std::out_of_range&) {
	}
	// Check for float
	try {
		float floatValue = std::stof(literal);
		if (floatValue < -std::numeric_limits<float>::max() || floatValue > std::numeric_limits<float>::max()) {
			throw std::out_of_range("Float out of range");
		}
		result.f = floatValue;
		result.hasFloat = true;
	} catch (const std::invalid_argument&) {
	} catch (const std::out_of_range&) {
	}
	// Check for double
	try {
		double doubleValue = std::stod(literal);
		if (doubleValue < -std::numeric_limits<double>::max() || doubleValue > std::numeric_limits<double>::max()) {
			throw std::out_of_range("Double out of range");
		}
		result.d = doubleValue;
		result.hasDouble = true;
	} catch (const std::invalid_argument&) {
	} catch (const std::out_of_range&) {
	}
	// If all conversions fail, throw an exception
	if (!result.hasChar && !result.hasInt && !result.hasFloat && !result.hasDouble) {
		throw std::invalid_argument("Invalid literal");
	}
	return result;
}

// Print the result
void ScalarConverter::printResult(const Result& r) {
	if (r.isNaN) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	} else if (r.isInf) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: inf" << std::endl;
		std::cout << "double: inf" << std::endl;
	} else {
		// Print char
		if (r.hasChar && std::isprint(r.c)) {
			std::cout << "char: '" << r.c << "'" << std::endl;
		} else {
			std::cout << "char: non displayable" << std::endl;
		}

		// Print int
		if (r.hasInt) {
			std::cout << "int: " << r.i << std::endl;
		} else {
			std::cout << "int: impossible" << std::endl;
		}

		// Print float
		if (r.hasFloat) {
			float val = r.f;
			if (val == -0.0f) {
				val = 0.0f;	 // Handle -0.0 case
			}
			if (std::isinf(val) || std::isnan(val)) {
				std::cout << "float: " << (std::isnan(val) ? "nanf" : (val < 0 ? "-inff" : "+inff")) << std::endl;
			} else {
				std::cout.precision(1);
				std::cout.setf(std::ios_base::fixed);
				std::cout << "float: " << val << "f" << std::endl;
			}
		} else {
			std::cout << "float: impossible" << std::endl;
		}

		// Print double
		if (r.hasDouble) {
			double val = r.d;
			if (val == -0.0) {
				val = 0.0;	// Handle -0.0 case
			}
			if (std::isinf(val) || std::isnan(val)) {
				std::cout << "double: " << (std::isnan(val) ? "nan" : (val < 0 ? "-inf" : "+inf")) << std::endl;
			} else {
				std::cout.precision(1);
				std::cout.setf(std::ios_base::fixed);
				std::cout << "double: " << val << std::endl;
			}
		} else {
			std::cout << "double: impossible" << std::endl;
		}
	}
}