#include <string>

#pragma once

class ScalarConverter {
   public:
	// Holds every possible converted value
	struct Result {
		char c;
		int i;
		float f;
		double d;
		bool hasChar = false;
		bool hasInt = false;
		bool hasFloat = false;
		bool hasDouble = false;
		bool isNaN = false;
		bool isInf = false;
	};

	// constructors and destructors
	ScalarConverter();
	ScalarConverter(const ScalarConverter&);
	ScalarConverter& operator=(const ScalarConverter&);
	~ScalarConverter();

	// Entry point: parses, converts & prints
	static void convert(const std::string& literal);

   private:
	// Steps: parse → convert → print
	static Result parseLiteral(const std::string& literal);
	static Result convertAll(const std::string& literal);
	static void printResult(const Result& r);
};
