#include <iostream>
#include <string>

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
