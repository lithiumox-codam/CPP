#include "Fixed.hpp"

#include <cmath>
#include <iostream>

Fixed::Fixed() : _value(0) { std::cout << BLUE << "Default constructor called" << RESET << std::endl; }

Fixed::Fixed(const Fixed &fixed) {
	*this = fixed;
	std::cout << BLUE << "Copy constructor called" << RESET << std::endl;
}

Fixed::Fixed(const int value) { _value = value << _fractionalBits; }

Fixed::Fixed(const float value) { _value = static_cast<int>(std::roundf(value * (1 << _fractionalBits))); }

Fixed::~Fixed() { std::cout << RED << "Destructor called" << RESET << std::endl; }

Fixed &Fixed::operator=(const Fixed &fixed) {
	if (this == &fixed) return *this;
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

bool Fixed::operator>(const Fixed &other) const { return this->getRawBits() > other.getRawBits(); }

bool Fixed::operator<(const Fixed &other) const { return this->getRawBits() < other.getRawBits(); }

bool Fixed::operator>=(const Fixed &other) { return this->getRawBits() >= other.getRawBits(); }

bool Fixed::operator<=(const Fixed &other) { return this->getRawBits() <= other.getRawBits(); }

bool Fixed::operator==(const Fixed &other) { return this->getRawBits() == other.getRawBits(); }

bool Fixed::operator!=(const Fixed &other) { return this->getRawBits() != other.getRawBits(); }

Fixed Fixed::operator+(const Fixed &other) {
	Fixed tmp(this->toFloat() + other.toFloat());
	return tmp;
}

Fixed Fixed::operator-(const Fixed &other) {
	Fixed tmp(this->toFloat() - other.toFloat());
	return tmp;
}

Fixed Fixed::operator*(const Fixed &other) {
	Fixed tmp(this->toFloat() * other.toFloat());
	return tmp;
}

Fixed Fixed::operator/(const Fixed &other) {
	Fixed tmp(this->toFloat() / other.toFloat());
	return tmp;
}

// Pre increment
Fixed Fixed::operator++() {
	this->_value++;
	return *this;
}

// Post increment
Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	this->_value++;
	return tmp;
}

// Pre decrement
Fixed Fixed::operator--() {
	this->_value--;
	return *this;
}

// Post decrement
Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	this->_value--;
	return tmp;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) { return a > b ? a : b; }

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) { return a > b ? a : b; }

Fixed &Fixed::min(Fixed &a, Fixed &b) { return a < b ? a : b; }

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) { return a < b ? a : b; }
