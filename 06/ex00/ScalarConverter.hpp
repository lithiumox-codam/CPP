#pragma once

#include <string>

class ScalarConverter {
   public:
	enum class Type { CHAR, INT, FLOAT, DOUBLE, INVALID };

	static void convert(const std::string& literal);

   private:
	// class must not be instantiated or copied so delete it is
	ScalarConverter() = delete;
	ScalarConverter(const ScalarConverter&) = delete;
	ScalarConverter& operator=(const ScalarConverter&) = delete;
	~ScalarConverter() = delete;
	// Steps: detect → convert → print
	static Type detectType(const std::string& literal);
	static void convertAndDisplay(const std::string& literal, Type type);
	static void displayChar(double value, bool impossible);
	static void displayInt(double value, bool impossible);
	static void displayFloat(double value);
	static void displayDouble(double value);
	static bool isSpecialFloat(const std::string& literal);
	static bool isSpecialDouble(const std::string& literal);
};
