#include "./Fixed.hpp"

bool operator>(const Fixed &a, const Fixed &b) { return a.getRawBits() > b.getRawBits(); }

bool operator<(const Fixed &a, const Fixed &b) { return a.getRawBits() < b.getRawBits(); }

bool operator>=(const Fixed &a, const Fixed &b) { return a.getRawBits() >= b.getRawBits(); }

bool operator<=(const Fixed &a, const Fixed &b) { return a.getRawBits() <= b.getRawBits(); }

bool operator==(const Fixed &a, const Fixed &b) { return a.getRawBits() == b.getRawBits(); }

bool operator!=(const Fixed &a, const Fixed &b) { return a.getRawBits() != b.getRawBits(); }

Fixed operator+(const Fixed &a, const Fixed &b) {
	Fixed tmp(a.toFloat() + b.toFloat());
	return tmp;
}

Fixed operator-(const Fixed &a, const Fixed &b) {
	Fixed tmp(a.toFloat() - b.toFloat());
	return tmp;
}

Fixed operator*(const Fixed &a, const Fixed &b) {
	Fixed tmp(a.toFloat() * b.toFloat());
	return tmp;
}

Fixed operator/(const Fixed &a, const Fixed &b) {
	Fixed tmp(a.toFloat() / b.toFloat());
	return tmp;
}

// Pre increment
Fixed &Fixed::operator++() {
	this->_value++;
	return *this;
}

// Post increment
Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	operator++();
	return tmp;
}

// Pre decrement
Fixed &Fixed::operator--() {
	this->_value--;
	return *this;
}

// Post decrement
Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	operator--();
	return tmp;
}
