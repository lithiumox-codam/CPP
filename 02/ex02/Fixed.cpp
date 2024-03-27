#include "Fixed.hpp"

#include <cmath>
#include <iostream>

Fixed::Fixed() : _value(0) {}

Fixed::Fixed(const Fixed &fixed) { *this = fixed; }

Fixed::Fixed(const int value) { _value = value << _fractionalBits; }

Fixed::Fixed(const float value) { _value = static_cast<int>(std::roundf(value * (1 << _fractionalBits))); }

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

Fixed &Fixed::operator=(const Fixed &fixed) {
	_value = fixed.getRawBits();
	return *this;
}

int Fixed::getRawBits() const { return _value; }

void Fixed::setRawBits(int const raw) { _value = raw; }

int Fixed::toInt() const { return _value >> _fractionalBits; }

float Fixed::toFloat() const { return static_cast<float>(_value) / (1 << _fractionalBits); }

std::ostream &operator<<(std::ostream &out, const Fixed &value) {
	out << value.toFloat();
	return out;
}
