#include <iostream>

#include "Fixed.hpp"

void print_to_start(std::string name, const Fixed& x) {
	std::cout << "Initial value of " << name << " is " << x << std::endl;
}

void test_to_int(std::string name, const Fixed& x) {
	std::cout << name << " is " << x.toInt() << " as integer" << std::endl;
}

void test_operators(std::string name, Fixed* x, Fixed* test) {
	std::cout << "Initial value of " << name << " is " << *x << std::endl;
	*x = *x / *test;
	std::cout << name << " / " << *test << " is " << *x << std::endl;
	*x = *x + *test;
	std::cout << name << " + " << *test << " is " << *x << std::endl;
	*x = *x * *test;
	std::cout << name << " * " << *test << " is " << *x << std::endl;
	*x = *x - *test;
	std::cout << name << " - " << *test << " is " << *x << std::endl;
}

static void print_comp(std::string comp, Fixed& x, Fixed& test) {
	std::cout << x << " " << comp << " " << test << std::endl;
}

void test_comparison(std::string name, Fixed& x, Fixed& test) {
	std::cout << "Initial value of " << name << " is " << x << std::endl;
	if (x > test) print_comp(">", x, test);
	if (x < test) print_comp("<", x, test);
	if (x >= test) print_comp(">=", x, test);
	if (x <= test) print_comp("<=", x, test);
	if (x == test) print_comp("==", x, test);
	if (x != test) print_comp("!=", x, test);
}

void test_min_max(std::string name, Fixed& x, Fixed& test) {
	std::cout << "Initial value of " << name << " is " << x << std::endl;
	std::cout << "Min of " << x << " and " << test << " is " << Fixed::min(x, test) << std::endl;
	std::cout << "Max of " << x << " and " << test << " is " << Fixed::max(x, test) << std::endl;
}

void test_pre_post(std::string name, Fixed& x) {
	std::cout << "Initial value of " << name << " is " << x << std::endl;
	std::cout << "Pre-increment of " << name << " is " << ++x << std::endl;
	std::cout << "Post-increment of " << name << " is " << x++ << std::endl;
	std::cout << "Value of " << name << " after post-increment is " << x << std::endl;
	std::cout << "Pre-decrement of " << name << " is " << --x << std::endl;
	std::cout << "Post-decrement of " << name << " is " << x-- << std::endl;
	std::cout << "Value of " << name << " after post-decrement is " << x << std::endl;
}

int main(void) {
	const std::string names[] = {"a", "b", "c", "d"};
	Fixed values[] = {1234.4321f, 10, 42.42f, 10};
	Fixed testValues[] = {20, 5, 2.001f, 15.45f};

	for (int i = 0; i < 4; i++) print_to_start(names[i], values[i]);

	std::cout << "\nChecking toInt function\n" << std::endl;
	for (int i = 0; i < 4; i++) test_to_int(names[i], values[i]);

	std::cout << "\nChecking arithmetic operators\n" << std::endl;
	for (int i = 0; i < 4; i++) test_operators(names[i], &values[i], &testValues[i]);

	std::cout << "\nChecking comparison operators\n" << std::endl;
	for (int i = 0; i < 4; i++) test_comparison(names[i], values[i], testValues[i]);

	std::cout << "\nChecking min and max functions\n" << std::endl;
	for (int i = 0; i < 4; i++) test_min_max(names[i], values[i], testValues[i]);

	std::cout << "\nChecking pre and post increment and decrement operators\n" << std::endl;
	for (int i = 0; i < 4; i++) test_pre_post(names[i], values[i]);

	return 0;
}

// int main(void) {
// 	Fixed a;
// 	Fixed const b(Fixed(5.05f) * Fixed(2));
// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << b << std::endl;
// 	std::cout << Fixed::max(a, b) << std::endl;
// 	return 0;
// }
