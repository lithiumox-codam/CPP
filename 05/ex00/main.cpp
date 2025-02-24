#include <iostream>
#include "Bureaucrat.hpp"

int main() {
    try {
        // Testing the constructor within valid range
        Bureaucrat bureaucratA("Alice", 2);
        std::cout << "Created: " << bureaucratA << std::endl;

        // Use incrementGrade() - should go from grade 2 to grade 1, which is valid
        std::cout << "Incrementing " << bureaucratA.getName() << "'s grade..." << std::endl;
        bureaucratA.incrementGrade();
        std::cout << bureaucratA << std::endl;

        // This increment attempt should throw GradeTooHighException (grade 1 -> would become 0)
        std::cout << "Incrementing " << bureaucratA.getName() << "'s grade again..." << std::endl;
        bureaucratA.incrementGrade();  // This will throw
        std::cout << bureaucratA << std::endl; // Not reached
    }
    catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "-------------------------------------------" << std::endl;

    try {
        // Testing bureaucrat creation with invalid grade
        std::cout << "Attempting to create bureaucrat with invalid grade..." << std::endl;
        Bureaucrat bureaucratB("Bob", 151); // This should throw GradeTooLowException
        std::cout << bureaucratB << std::endl; // Not reached
    }
    catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "-------------------------------------------" << std::endl;

    try {
        // Valid grade
        Bureaucrat bureaucratC("Charlie", 149);
        std::cout << "Created: " << bureaucratC << std::endl;

        // Decrement multiple times
        std::cout << "Decrementing " << bureaucratC.getName() << "'s grade multiple times..." << std::endl;
        for (int i = 0; i < 3; ++i) {
            bureaucratC.decrementGrade();
            std::cout << bureaucratC << std::endl;
        }

        // Attempting to decrement below grade 150 --> next will be 151
        std::cout << "Trying to decrement " << bureaucratC.getName() << "'s grade beyond the limit..." << std::endl;
        while (true) {
            bureaucratC.decrementGrade(); // Will throw when it goes beyond 150
            std::cout << bureaucratC << std::endl;
        }
    }
    catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
