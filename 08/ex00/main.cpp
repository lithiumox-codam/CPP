#include <iostream>
#include <list>
#include <vector>

#include "EasyFind.hpp"

int main(void) {
	std::vector<int> vec = {1, 2, 3, 4, 5};
	std::list<int> lst = {10, 20, 30, 40, 50};

	std::cout << "\n┌───────────────────────────────────────┐\n";
	std::cout << "│ Searching for 3 in vector             │\n";
	std::cout << "└───────────────────────────────────────┘\n";
	try {
		auto foundInVec = easyfind(vec, 3);
		std::cout << "✓ Found: " << *foundInVec << '\n';
	} catch (const std::runtime_error& e) {
		std::cout << "✗ Error: " << e.what() << '\n';
	}

	std::cout << "\n┌───────────────────────────────────────┐\n";
	std::cout << "│ Searching for 20 in list              │\n";
	std::cout << "└───────────────────────────────────────┘\n";
	try {
		auto foundInList = easyfind(lst, 20);
		std::cout << "✓ Found: " << *foundInList << '\n';
	} catch (const std::runtime_error& e) {
		std::cout << "✗ Error: " << e.what() << '\n';
	}

	std::cout << "\n┌───────────────────────────────────────┐\n";
	std::cout << "│ Searching for 6 in vector (not found) │\n";
	std::cout << "└───────────────────────────────────────┘\n";
	try {
		auto notFoundInVec = easyfind(vec, 6);
		std::cout << "✓ Found: " << *notFoundInVec << '\n';
	} catch (const std::runtime_error& e) {
		std::cout << "✗ Error: " << e.what() << '\n';
	}

	std::cout << "\n┌───────────────────────────────────────┐\n";
	std::cout << "│ Searching for 100 in list (not found) │\n";
	std::cout << "└───────────────────────────────────────┘\n";
	try {
		auto notFoundInList = easyfind(lst, 100);
		std::cout << "✓ Found: " << *notFoundInList << '\n';
	} catch (const std::runtime_error& e) {
		std::cout << "✗ Error: " << e.what() << '\n';
	}

	return 0;
}