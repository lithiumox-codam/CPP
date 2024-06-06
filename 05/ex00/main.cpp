#include <iostream>

#include "./Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat b("Mark", 2);
		std::cout << b.getName() << "\'s grade test:" << std::endl;
		std::cout << "Incrementing grade..." << std::endl;

		b.incrementGrade();
		std::cout << b.getGrade() << std::endl;

		std::cout << "Decrementing grade..." << std::endl;
		for (int i = 0; i < 149; i++) {
			std::cout << b.getGrade() << " -> ";
			b.decrementGrade();
		}
		std::cout << std::endl;

		Bureaucrat c("Geert", 145);
		std::cout << c.getName() << "\'s grade test:" << std::endl;
		std::cout << "Decrementing grade..." << std::endl;
		for (int i = 0; i < 10; i++) {
			std::cout << c.getGrade() << " -> ";
			c.decrementGrade();
		}
		std::cout << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
