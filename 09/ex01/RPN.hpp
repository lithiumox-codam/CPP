#pragma once

#include <cctype>
#include <cstdlib>
#include <string>

class RPN {
   private:
	RPN() = delete;
	RPN(const RPN& src) = delete;
	RPN& operator=(const RPN& rhs) = delete;
	~RPN() = delete;

   public:
	static void evaluate(const std::string& expression);
};