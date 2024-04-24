#include <iostream>
#include <string>

/**
 * @brief This exercise shows how pointers and references work in C++,
 * All pointers and references lead to the same address and print out
 * the exact same strings.
 *
 * @info Pointers are still pointers. References are basically aliases.
 * They are not pointers, but they are still addresses. They are just
 * notated differently.
 */
int main() {
	std::string s = "HI THIS IS BRAIN";
	std::string *ptr = &s;
	std::string &ref = s;

	/* Prints the address of s */
	std::cout << &s << std::endl;
	/* The value of ptr which is the address of s */
	std::cout << ptr << std::endl;
	/* The address of ref which is the address of s */
	std::cout << &ref << std::endl;

	/* Here you'll see that they all print the string */
	std::cout << s << std::endl;
	std::cout << *ptr << std::endl;
	std::cout << ref << std::endl;
	return 0;
}
