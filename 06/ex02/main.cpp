#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include "Base.hpp"

/**
 * @brief This program demonstrates polymorphism in C++ by creating a
 * hierarchy of classes derived from a base class.
 */
int main() {
	Base* arr[10];

	std::cout << "Generating 10 random Base objects..." << std::endl;
	for (int i = 0; i < 10; ++i) {
		arr[i] = generate();
	}

	std::cout << "\n+-------+----------------+----------------+" << std::endl;
	std::cout << "| Index |   By pointer   |  By reference  |" << std::endl;
	std::cout << "+-------+----------------+----------------+" << std::endl;

	for (int i = 0; i < 10; ++i) {
		// Capture the output for pointer identification
		std::ostringstream ptr_output;
		std::streambuf* old_cout_buf = std::cout.rdbuf();
		std::cout.rdbuf(ptr_output.rdbuf());
		identify(arr[i]);
		std::cout.rdbuf(old_cout_buf);

		// Capture the output for reference identification
		std::ostringstream ref_output;
		std::cout.rdbuf(ref_output.rdbuf());
		identify(*arr[i]);
		std::cout.rdbuf(old_cout_buf);

		// Clean the captured strings (remove newlines and extra spaces)
		std::string ptr_str = ptr_output.str();
		std::string ref_str = ref_output.str();

		// Remove newlines and trim whitespace (without std::algorithm)
		size_t start = 0;
		while (start < ptr_str.length() &&
			   (ptr_str[start] == ' ' || ptr_str[start] == '\t' || ptr_str[start] == '\n')) {
			start++;
		}
		ptr_str.erase(0, start);

		size_t end = ptr_str.length();
		while (end > 0 && (ptr_str[end - 1] == ' ' || ptr_str[end - 1] == '\t' || ptr_str[end - 1] == '\n')) {
			end--;
		}
		ptr_str.erase(end, ptr_str.length() - end);

		start = 0;
		while (start < ref_str.length() &&
			   (ref_str[start] == ' ' || ref_str[start] == '\t' || ref_str[start] == '\n')) {
			start++;
		}
		ref_str.erase(0, start);

		end = ref_str.length();
		while (end > 0 && (ref_str[end - 1] == ' ' || ref_str[end - 1] == '\t' || ref_str[end - 1] == '\n')) {
			end--;
		}
		ref_str.erase(end, ref_str.length() - end);

		// Print the table row
		std::cout << "| " << std::setw(5) << std::right << i << " | " << std::setw(14) << std::left << ptr_str << " | "
				  << std::setw(14) << std::left << ref_str << " |" << std::endl;
	}

	std::cout << "+-------+----------------+----------------+" << std::endl;

	// Clean up dynamically allocated memory
	for (int i = 0; i < 10; ++i) {
		delete arr[i];
	}

	// Test with a NULL pointer
	std::cout << "\nIdentifying NULL pointer:" << std::endl;
	Base* nullPtr = NULL;
	identify(nullPtr);

	// Test identify by reference with a known type
	std::cout << "\nIdentifying known types by reference:" << std::endl;
	A a;
	B b;
	C c;
	std::cout << "Identifying A: ";
	identify(a);
	std::cout << "Identifying B: ";
	identify(b);
	std::cout << "Identifying C: ";
	identify(c);

	return 0;
}