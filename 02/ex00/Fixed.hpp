#ifndef __FIXED_H__
#define __FIXED_H__

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

#endif
