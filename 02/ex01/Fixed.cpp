#include "Fixed.hpp"

#include <cmath>
#include <iostream>

Fixed::Fixed() : _value(0) { std::cout << BLUE << "Default constructor called" << RESET << std::endl; }

Fixed::Fixed(const Fixed &fixed) {
	std::cout << BLUE << "Copy constructor called" << RESET << std::endl;
	*this = fixed;
}

Fixed::Fixed(const int value) {
	std::cout << BLUE << "Int constructor called" << RESET << std::endl;
	_value = value << _fractionalBits;
}

Fixed::Fixed(const float value) {
	std::cout << BLUE << "Float constructor called" << RESET << std::endl;
	_value = static_cast<int>(std::roundf(value * (1 << _fractionalBits)));
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

int Fixed::toInt() const { return _value >> _fractionalBits; }

float Fixed::toFloat() const { return static_cast<float>(_value) / (1 << _fractionalBits); }

std::ostream &operator<<(std::ostream &out, const Fixed &value) {
	out << value.toFloat();
	return out;
}
