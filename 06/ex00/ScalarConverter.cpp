#include "ScalarConverter.hpp"

#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

void ScalarConverter::convert(const std::string& literal) {
	Type type = detectType(literal);
	if (type == Type::INVALID) {
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: impossible\n";
		std::cout << "double: impossible\n";
		return;
	}
	convertAndDisplay(literal, type);
}

ScalarConverter::Type ScalarConverter::detectType(const std::string& literal) {
	if (literal.empty()) return Type::INVALID;

	// Check for special float/double literals first
	if (isSpecialFloat(literal) || isSpecialDouble(literal)) {
		return literal.back() == 'f' ? Type::FLOAT : Type::DOUBLE;
	}

	// Check for char literal
	if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0])) {
		return Type::CHAR;
	}

	// Check for float literal (ends with 'f')
	if (literal.back() == 'f' && literal.length() > 1) {
		try {
			std::stof(literal);
			return Type::FLOAT;
		} catch (...) {
			return Type::INVALID;
		}
	}

	// Check for double literal (contains decimal point)
	if (literal.find('.') != std::string::npos) {
		try {
			std::stod(literal);
			return Type::DOUBLE;
		} catch (...) {
			return Type::INVALID;
		}
	}

	// Check for int literal
	try {
		long val = std::stol(literal);
		if (val >= std::numeric_limits<int>::min() && val <= std::numeric_limits<int>::max()) {
			return Type::INT;
		}
	} catch (...) {
	}

	return Type::INVALID;
}

/**
 * Does the conversion to doubles so that we can handle all types uniformly.
 * Then displays the results for char, int, float, and double.
 */
void ScalarConverter::convertAndDisplay(const std::string& literal, Type type) {
	double value = 0.0;
	bool impossible = false;

	switch (type) {
		case Type::CHAR:
			value = static_cast<double>(literal[0]);
			break;
		case Type::INT:
			try {
				value = static_cast<double>(std::stoi(literal));
			} catch (...) {
				impossible = true;
			}
			break;
		case Type::FLOAT:
			try {
				float f = std::stof(literal);
				value = static_cast<double>(f);
				if (std::isnan(f) || std::isinf(f)) impossible = true;
			} catch (...) {
			}
			break;
		case Type::DOUBLE:
			try {
				value = std::stod(literal);
				if (std::isnan(value) || std::isinf(value)) impossible = true;
			} catch (...) {
			}
			break;
		default:
			impossible = true;
	}

	displayChar(value, impossible);
	displayInt(value, impossible);
	displayFloat(value);
	displayDouble(value);
}

void ScalarConverter::displayChar(double value, bool impossible) {
	if (impossible || std::isnan(value) || std::isinf(value)) {
		std::cout << "char: impossible\n";
	} else if (value < 0 || value > 127 || !std::isprint(static_cast<int>(value))) {
		std::cout << "char: Non displayable\n";
	} else {
		std::cout << "char: '" << static_cast<char>(value) << "'\n";
	}
}

void ScalarConverter::displayInt(double value, bool impossible) {
	if (impossible || std::isnan(value) || std::isinf(value) || value < std::numeric_limits<int>::min() ||
		value > std::numeric_limits<int>::max()) {
		std::cout << "int: impossible\n";
	} else {
		std::cout << "int: " << static_cast<int>(value) << '\n';
	}
}

void ScalarConverter::displayFloat(double value) {
	if (std::isnan(value)) {
		std::cout << "float: nanf\n";
	} else if (std::isinf(value)) {
		std::cout << "float: " << (value < 0 ? "-inff" : "+inff") << '\n';
	} else if (value < -std::numeric_limits<float>::max() || value > std::numeric_limits<float>::max()) {
		std::cout << "float: impossible\n";
	} else {
		float f = static_cast<float>(value);
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f\n";
	}
}

void ScalarConverter::displayDouble(double value) {
	if (std::isnan(value)) {
		std::cout << "double: nan\n";
	} else if (std::isinf(value)) {
		std::cout << "double: " << (value < 0 ? "-inf" : "+inf") << '\n';
	} else {
		std::cout << "double: " << std::fixed << std::setprecision(1) << value << '\n';
	}
}

bool ScalarConverter::isSpecialFloat(const std::string& literal) {
	return literal == "nanf" || literal == "+inff" || literal == "-inff" || literal == "inff";
}

bool ScalarConverter::isSpecialDouble(const std::string& literal) {
	return literal == "nan" || literal == "+inf" || literal == "-inf" || literal == "inf";
}