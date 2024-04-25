#include "Fixed.hpp"

#include <iostream>

Fixed::Fixed() : _value(0) { std::cout << BLUE << "Default constructor called" << RESET << std::endl; }

Fixed::Fixed(const Fixed &fixed) {
	std::cout << BLUE << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::~Fixed() { std::cout << RED << "Destructor called" << RESET << std::endl; }

Fixed &Fixed::operator=(const Fixed &fixed) {
	std::cout << YELLOW << "Assignation operator called" << RESET << std::endl;
	_value = fixed.getRawBits();
	return *this;
}

int Fixed::getRawBits() const {
	std::cout << TEAL << "getRawBits member function called" << RESET << std::endl;
	return _value;
}

void Fixed::setRawBits(int const raw) {
	std::cout << TEAL << "setRawBits member function called" << RESET << std::endl;
	_value = raw;
}
