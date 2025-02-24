#include <cassert>
#include <iostream>

#include "Bureaucrat.hpp"

/**
 * @brief This tests the Bureaucrat class by creating an instance of Bureaucrat with grade 2,
 * incrementing the grade, and then attempting to increment the grade beyond the upper limit.
 * This should throw a GradeTooHighException.
 */
void testAlice() {
	std::cout << "[testAlice] Creating Bureaucrat 'Alice' with grade 2." << std::endl;
	Bureaucrat bureaucratA("Alice", 2);
	std::cout << "[testAlice] 'Alice' created with grade: " << bureaucratA.getGrade() << std::endl;
	assert(bureaucratA.getGrade() == 2);

	std::cout << "[testAlice] Incrementing 'Alice' grade." << std::endl;
	bureaucratA.incrementGrade();
	std::cout << "[testAlice] 'Alice' grade after increment: " << bureaucratA.getGrade() << std::endl;
	assert(bureaucratA.getGrade() == 1);

	// Next increment should throw GradeTooHighException
	std::cout << "[testAlice] Attempting to increment 'Alice' grade beyond upper limit." << std::endl;
	bool highExceptionThrown = false;
	try {
		bureaucratA.incrementGrade();
	} catch (const std::exception &e) {
		highExceptionThrown = true;
		std::cout << "[testAlice] Caught expected exception: " << e.what() << std::endl;
	}
	assert(highExceptionThrown);
}

/**
 * @brief This tests the Bureaucrat class by attempting to create an instance of Bureaucrat with
 * an invalid grade of 151. This should throw a GradeTooLowException.
 */
void testBob() {
	std::cout << "[testBob] Attempting to create Bureaucrat 'Bob' with invalid grade 151." << std::endl;
	bool lowExceptionThrown = false;
	try {
		Bureaucrat bureaucratB("Bob", 151);
	} catch (const std::exception &e) {
		lowExceptionThrown = true;
		std::cout << "[testBob] Caught expected exception: " << e.what() << std::endl;
	}
	assert(lowExceptionThrown);
}

/**
 * @brief This tests the Bureaucrat class by creating an instance of Bureaucrat with grade 149,
 * decrementing the grade, and then attempting to decrement the grade beyond the lower limit.
 * This should throw a GradeTooLowException.
 */
void testCharlie() {
	std::cout << "[testCharlie] Creating Bureaucrat 'Charlie' with grade 149." << std::endl;
	Bureaucrat bureaucratC("Charlie", 149);
	std::cout << "[testCharlie] 'Charlie' created with grade: " << bureaucratC.getGrade() << std::endl;
	assert(bureaucratC.getGrade() == 149);

	std::cout << "[testCharlie] Decrementing 'Charlie' grade." << std::endl;
	bureaucratC.decrementGrade();
	std::cout << "[testCharlie] 'Charlie' grade after decrement: " << bureaucratC.getGrade() << std::endl;
	assert(bureaucratC.getGrade() == 150);

	std::cout << "[testCharlie] Attempting to decrement 'Charlie' grade beyond lower limit." << std::endl;
	bool lowExceptionThrown = false;
	try {
		bureaucratC.decrementGrade();
	} catch (const std::exception &e) {
		lowExceptionThrown = true;
		std::cout << "[testCharlie] Caught expected exception: " << e.what() << std::endl;
	}
	assert(lowExceptionThrown);
}

/**
 * @brief This tests the Bureaucrat class by creating an instance of Bureaucrat with grade 2,
 * and a Form that requires grade 1 to sign. The Bureaucrat should fail to sign the form
 * initially, but after incrementing the grade to 1, the Bureaucrat should be able to sign the form.
 */
void testFormSigning() {
	std::cout << "[testFormSigning] Creating Bureaucrat 'Alice' with grade 2." << std::endl;
	Bureaucrat alice("Alice", 2);
	std::cout << "[testFormSigning] Creating Form 'TaxForm' requiring grade 1 to sign." << std::endl;
	Form taxForm("TaxForm", 1, 1);

	std::cout << "[testFormSigning] Attempting to sign the form with Alice." << std::endl;
	alice.signForm(taxForm);  // Should fail because Alice's grade is 2, but the form requires grade 1

	std::cout << "[testFormSigning] Incrementing Alice's grade to 1." << std::endl;
	alice.incrementGrade();
	std::cout << "[testFormSigning] Attempting to sign the form again." << std::endl;
	alice.signForm(taxForm);  // Should succeed now
}

int main() {
	testAlice();
	std::cout << "\n\n********** testAlice passed **********\n\n";

	testBob();
	std::cout << "\n\n********** testBob passed **********\n\n";

	testCharlie();
	std::cout << "\n\n********** testCharlie passed **********\n\n";

	testFormSigning();
	std::cout << "\n\n********** testFormSigning passed **********\n\n";

	std::cout << "\n\n********** All tests passed successfully **********\n\n";
	return 0;
}