#include <iostream>

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void testShrubberyForm() {
	std::cout << "\n=== Testing ShrubberyCreationForm ===\n";

	try {
		Bureaucrat lowGrade("Bob", 140);
		Bureaucrat highGrade("Alice", 137);
		ShrubberyCreationForm form("home");

		std::cout << "\n--- Initial Form State ---\n";
		std::cout << form << std::endl;

		// Test execution without signature (should fail)
		std::cout << "\nAttempting to execute before signing...\n";
		try {
			lowGrade.executeForm(form);
		} catch (std::exception& e) {
			std::cout << "Expected error: " << e.what() << std::endl;
		}

		// Sign the form
		std::cout << "\nAttempting to sign with grade " << lowGrade.getGrade() << "...\n";
		lowGrade.signForm(form);

		// Test execution with insufficient grade (should fail)
		std::cout << "\nAttempting to execute with insufficient grade...\n";
		try {
			lowGrade.executeForm(form);
		} catch (std::exception& e) {
			std::cout << "Expected error: " << e.what() << std::endl;
		}

		// Test execution with sufficient grade (should pass)
		std::cout << "\nAttempting to execute with sufficient grade...\n";
		highGrade.executeForm(form);
	} catch (std::exception& e) {
		std::cout << "Unexpected Exception: " << e.what() << std::endl;
	}
}

void testRobotomyForm() {
	std::cout << "\n=== Testing RobotomyRequestForm ===\n";

	try {
		Bureaucrat boss("Boss", 45);
		RobotomyRequestForm form("intern");

		std::cout << "\n--- Initial Form State ---\n";
		std::cout << form << std::endl;

		// Sign the form
		std::cout << "\nSigning the RobotomyRequestForm...\n";
		boss.signForm(form);

		// Test multiple executions to see randomization
		for (int i = 0; i < 3; i++) {
			std::cout << "\nExecution attempt " << i + 1 << ":\n";
			boss.executeForm(form);
		}
	} catch (std::exception& e) {
		std::cout << "Unexpected Exception: " << e.what() << std::endl;
	}
}

void testPresidentialForm() {
	std::cout << "\n=== Testing PresidentialPardonForm ===\n";

	try {
		Bureaucrat president("President", 5);
		Bureaucrat intern("Intern", 150);
		PresidentialPardonForm form("Arthur Dent");

		std::cout << "\n--- Initial Form State ---\n";
		std::cout << form << std::endl;

		// Test signing with low grade (should fail)
		std::cout << "\nAttempting to sign with intern...\n";
		try {
			intern.signForm(form);
			// If no exception is thrown, the form should not be signed.
		} catch (std::exception& e) {
			std::cout << "Expected error: " << e.what() << std::endl;
		}

		// Sign with sufficient grade
		std::cout << "\nAttempting to sign with president...\n";
		president.signForm(form);

		// Test execution (should pass)
		std::cout << "\nAttempting to execute with president...\n";
		president.executeForm(form);
	} catch (std::exception& e) {
		std::cout << "Unexpected Exception: " << e.what() << std::endl;
	}
}

int main() {
	std::cout << "\n********** Starting Form Tests **********\n";
	testShrubberyForm();
	testRobotomyForm();
	testPresidentialForm();

	std::cout << "\n********** All tests completed **********\n";
	return 0;
}