#include <iostream>
#include <string>

/**
 * @brief This exercise shows how pointers and references work in C++,
 * All pointers and references lead to the same address and print out
 * the exact same strings.
 */
int main() {
	std::string s = "HI THIS IS BRAIN";
	std::string *ptr = &s;
	std::string &ref = s;

	/* This will print the adresses */
	std::cout << &s << std::endl;
	std::cout << ptr << std::endl;
	std::cout << &ref << std::endl;

	/* Here you'll see that they all print the string */
	std::cout << s << std::endl;
	std::cout << *ptr << std::endl;
	std::cout << ref << std::endl;
	return 0;
}
