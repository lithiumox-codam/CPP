#pragma once

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
	Fixed &operator=(const Fixed &other);
	int getRawBits(void) const;
	void setRawBits(int const raw);

   private:
	int _value;
	static const int _fractionalBits = 8;
};
