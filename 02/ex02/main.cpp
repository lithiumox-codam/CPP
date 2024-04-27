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

static void print_comp(std::string comp, const Fixed& x, const Fixed& test) {
	std::cout << x << " " << comp << " " << test << std::endl;
}

void test_comparison(std::string name, const Fixed& x, const Fixed& test) {
	std::cout << "Initial value of " << name << " is " << x << std::endl;
	if (x > test) print_comp(">", x, test);
	if (x < test) print_comp("<", x, test);
	if (x >= test) print_comp(">=", x, test);
	if (x <= test) print_comp("<=", x, test);
	if (x == test) print_comp("==", x, test);
	if (x != test) print_comp("!=", x, test);
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

	return 0;
}
