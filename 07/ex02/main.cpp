#include <iostream>
#include <string>

#include "Array.hpp"

int main() {
	// Test default constructor (empty array)
	Array<int> empty;
	std::cout << "Empty array size: " << empty.size() << std::endl;

	// Test parametric constructor
	Array<int> numbers(5);
	std::cout << "Integer array size: " << numbers.size() << std::endl;

	// Fill the array with values
	for (unsigned int i = 0; i < numbers.size(); i++) {
		numbers[i] = i * 10;
		std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
	}

	// Test copy constructor
	Array<int> copy(numbers);
	std::cout << "\nAfter copy construction:" << std::endl;
	for (unsigned int i = 0; i < copy.size(); i++) {
		std::cout << "copy[" << i << "] = " << copy[i] << std::endl;
	}

	// Verify deep copy
	numbers[0] = 100;
	std::cout << "\nAfter modifying original:" << std::endl;
	std::cout << "numbers[0] = " << numbers[0] << std::endl;
	std::cout << "copy[0] = " << copy[0] << std::endl;

	// Test exception handling
	try {
		std::cout << "\nTrying to access out of bounds index..." << std::endl;
		numbers[10] = 0;
	} catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	// Test with strings
	Array<std::string> strings(3);
	strings[0] = "Hello";
	strings[1] = "World";
	strings[2] = "!";

	std::cout << "\nString array:" << std::endl;
	for (unsigned int i = 0; i < strings.size(); i++) {
		std::cout << strings[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}
