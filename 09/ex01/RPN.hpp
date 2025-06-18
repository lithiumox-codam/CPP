#pragma once

#include <cctype>
#include <cstdlib>
#include <string>

class RPN {
   private:
	RPN() = default;
	RPN(const RPN& src) = default;
	RPN& operator=(const RPN& rhs) = default;
	~RPN() = default;

   public:
	static void evaluate(const std::string& expression);
};