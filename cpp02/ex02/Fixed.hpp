#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int _value;
		static const int _bits = 8;

	public:
		Fixed();
		Fixed(const int number);
		Fixed(const float fnumber);
		Fixed(const Fixed &copy);
		Fixed &operator=(const Fixed &copy);
		~Fixed();

	float toFloat( void ) const;
	int toInt( void ) const;

	int getRawBits(void) const;
	void setRawBits(int const raw);

	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);

	bool			operator>(const Fixed &other) const;
	bool			operator<(const Fixed &other) const;
	bool			operator>=(const Fixed &other) const;
	bool			operator<=(const Fixed &other) const;
	bool			operator==(const Fixed &other) const;
	bool			operator!=(const Fixed &other) const;
	Fixed			operator+(const Fixed &other) const;
	Fixed			operator-(const Fixed &other) const;
	Fixed			operator*(const Fixed &other) const;
	Fixed			operator/(const Fixed &other) const;
	Fixed			operator++(int);
	Fixed			&operator++(void);
	Fixed			operator--(int);
	Fixed			&operator--(void);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif