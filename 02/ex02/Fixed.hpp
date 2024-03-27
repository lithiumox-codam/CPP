#pragma once

#include <ostream>

class Fixed {
   public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &other);
	Fixed(const int value);
	Fixed(const float value);
	Fixed &operator=(const Fixed &other);
	int getRawBits(void) const;
	void setRawBits(int const raw);
	int toInt(void) const;
	float toFloat(void) const;
	Fixed &operator++();
	Fixed operator++(int);
	Fixed &operator--();
	Fixed operator--(int);

   private:
	int _value;
	static const int _fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &value);
bool operator>(const Fixed &a, const Fixed &b);
bool operator<(const Fixed &a, const Fixed &b);
bool operator>=(const Fixed &a, const Fixed &b);
bool operator<=(const Fixed &a, const Fixed &b);
bool operator==(const Fixed &a, const Fixed &b);
bool operator!=(const Fixed &a, const Fixed &b);
Fixed operator+(const Fixed &a, const Fixed &b);
Fixed operator-(const Fixed &a, const Fixed &b);
Fixed operator*(const Fixed &a, const Fixed &b);
Fixed operator/(const Fixed &a, const Fixed &b);
