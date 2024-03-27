#include <iostream>
#include <string>

/**
 * @brief Main function that demonstrates the use of pointers and references
 * in C++. It creates a string and then creates a pointer and a reference to
 * that string. It then prints the address of the string, the pointer and the
 * reference. It also prints the string, the string pointed to by the pointer
 * and the string referenced by the reference. The address of the string, the
 * pointer and the reference are different, but the string, the string pointed
 * to by the pointer and the string referenced by the reference are the same.
 */
int main() {
	std::string s = "HI THIS IS BRAIN";
	std::string *ptr = &s;
	std::string &ref = s;

	std::cout << &s << "\n";
	std::cout << &ptr << "\n";
	std::cout << &ref << "\n";

	std::cout << s << "\n";
	std::cout << *ptr << "\n";
	std::cout << ref << "\n";
	return 0;
}
