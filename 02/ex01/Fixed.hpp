#pragma once

#include <ostream>

#define BLUE "\033[34m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RED "\033[31m"
#define TEAL "\033[36m"
#define RESET "\033[0m"

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

   private:
	int _value;
	static const int _fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &value);
