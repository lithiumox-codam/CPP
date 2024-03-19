#include <iostream>

#include "Fixed.hpp"

int main(void) {
	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);
	a = Fixed(1234.4321f);
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	std::cout << "a starts at 10" << std::endl;
	a = Fixed(10);
	std::cout << "a is incremented by 1" << std::endl;
	a = a++;
	std::cout << "a is " << a << std::endl;
	std::cout << "a is pre incremented by 1" << std::endl;
	a = ++a;
	std::cout << "a is " << a << std::endl;
	a = a--;
	std::cout << "a is " << a << std::endl;
	a = --a;
	std::cout << "a is " << a << std::endl;

	a = a / Fixed(2);
	std::cout << "a is " << a << std::endl;
	a = a * Fixed(2);
	std::cout << "a is " << a << std::endl;
	a = a + Fixed(2);
	std::cout << "a is " << a << std::endl;
	a = a - Fixed(2);
	std::cout << "a is " << a << std::endl;

	if (a > Fixed(2)) std::cout << "a is greater than 2" << std::endl;
	if (a < Fixed(2)) std::cout << "a is less than 2" << std::endl;
	if (a >= Fixed(2)) std::cout << "a is greater or equal to 2" << std::endl;
	if (a <= Fixed(2)) std::cout << "a is less or equal to 2" << std::endl;
	if (a == Fixed(2)) std::cout << "a is equal to 2" << std::endl;
	if (a != Fixed(2)) std::cout << "a is not equal to 2" << std::endl;

	return 0;
}
