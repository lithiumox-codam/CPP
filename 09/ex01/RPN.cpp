#include "RPN.hpp"

#include <iostream>
#include <sstream>
#include <stack>

void RPN::evaluate(const std::string& expression) {
	std::stack<int> stack;
	std::stringstream ss(expression);
	std::string token;

	while (ss >> token) {
		if (token.length() == 1 && std::isdigit(token[0])) {
			stack.push(std::atoi(token.c_str()));
		} else if (token.length() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')) {
			if (stack.size() < 2) {
				std::cerr << "Error: insufficient arguments" << std::endl;
				return;
			}
			int b = stack.top();
			stack.pop();
			int a = stack.top();
			stack.pop();

			if (token[0] == '+') {
				stack.push(a + b);
			} else if (token[0] == '-') {
				stack.push(a - b);
			} else if (token[0] == '*') {
				stack.push(a * b);
			} else if (token[0] == '/') {
				if (b == 0) {
					std::cerr << "Error: division by zero!" << std::endl;
					return;
				}
				stack.push(a / b);
			}
		} else {
			std::cerr << "Error: invalid token" << std::endl;
			return;
		}
	}

	if (stack.size() != 1) {
		std::cerr << "Error: incorrect amont of operands" << std::endl;
		return;
	}

	std::cout << stack.top() << std::endl;
}