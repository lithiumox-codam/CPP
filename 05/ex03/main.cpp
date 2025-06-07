#include <iostream>

#include "Bureaucrat.hpp"
#include "Intern.hpp"
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

		// Test with Intern
		std::cout << "\n--- Testing with Intern ---\n";
		Intern intern;
		AForm* internForm = intern.makeForm("shrubbery creation", "garden");
		if (internForm) {
			std::cout << "Form created successfully:\n" << *internForm << std::endl;
			highGrade.signForm(*internForm);
			highGrade.executeForm(*internForm);
			delete internForm;
		}
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

		// Test with Intern
		std::cout << "\n--- Testing with Intern ---\n";
		Intern intern;
		AForm* internForm = intern.makeForm("robotomy request", "Bender");
		if (internForm) {
			std::cout << "Form created successfully:\n" << *internForm << std::endl;
			boss.signForm(*internForm);
			for (int i = 0; i < 2; i++) {
				std::cout << "\nIntern-created form execution attempt " << i + 1 << ":\n";
				boss.executeForm(*internForm);
			}
			delete internForm;
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

		// Test with Intern
		std::cout << "\n--- Testing with Intern ---\n";
		Intern internWorker;
		AForm* internForm = internWorker.makeForm("presidential pardon", "Ford Prefect");
		if (internForm) {
			std::cout << "Form created successfully:\n" << *internForm << std::endl;
			president.signForm(*internForm);
			president.executeForm(*internForm);
			delete internForm;
		}
	} catch (std::exception& e) {
		std::cout << "Unexpected Exception: " << e.what() << std::endl;
	}
}

void testIntern() {
	std::cout << "\n=== Testing Intern Class ===\n";

	try {
		Intern intern;
		Bureaucrat highLevel("Manager", 1);

		// Test valid form creation
		std::cout << "\n--- Testing Valid Form Creation ---\n";
		std::string validForms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
		std::string targets[3] = {"backyard", "criminal", "politician"};

		for (int i = 0; i < 3; i++) {
			std::cout << "\nTesting: " << validForms[i] << std::endl;
			AForm* form = intern.makeForm(validForms[i], targets[i]);
			if (form) {
				std::cout << "Successfully created: " << *form << std::endl;
				highLevel.signForm(*form);
				highLevel.executeForm(*form);
				delete form;
			} else {
				std::cout << "Failed to create form!" << std::endl;
			}
		}

		// Test invalid form creation
		std::cout << "\n--- Testing Invalid Form Creation ---\n";
		std::string invalidForms[3] = {"invalid form", "unknown request", "fake pardon"};

		for (int i = 0; i < 3; i++) {
			std::cout << "\nTesting invalid form: " << invalidForms[i] << std::endl;
			AForm* form = intern.makeForm(invalidForms[i], "target");
			if (form) {
				std::cout << "Unexpected: Form was created!" << std::endl;
				delete form;
			} else {
				std::cout << "Correctly returned nullptr for invalid form." << std::endl;
			}
		}

		// Test copy constructor and assignment operator
		std::cout << "\n--- Testing Copy Constructor and Assignment ---\n";
		Intern intern2(intern);
		Intern intern3;
		intern3 = intern;

		AForm* form1 = intern2.makeForm("shrubbery creation", "copy_test");
		AForm* form2 = intern3.makeForm("robotomy request", "assignment_test");

		if (form1 && form2) {
			std::cout << "Copy and assignment work correctly!" << std::endl;
			delete form1;
			delete form2;
		}

	} catch (std::exception& e) {
		std::cout << "Unexpected Exception in Intern test: " << e.what() << std::endl;
	}
}

int main() {
	std::cout << "\n********** Starting Form Tests **********\n";
	testShrubberyForm();
	testRobotomyForm();
	testPresidentialForm();
	testIntern();

	std::cout << "\n********** All tests completed **********\n";
	return 0;
}