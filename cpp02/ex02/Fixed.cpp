#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {}

Fixed::Fixed(const int number) {
	_value = number << _bits;
}

Fixed::Fixed(const float fnumber) {
	_value = roundf(fnumber * (1 << _bits));
}

Fixed::Fixed(const Fixed &copy) {
	this->_value = copy.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &copy) {
	if (this != &copy)
		this->_value = copy.getRawBits();
	return (*this);
}

Fixed::~Fixed() {}

int Fixed::getRawBits(void) const
{
    return this->_value;
}

void Fixed::setRawBits (int const raw)
{
    this->_value = raw;
}

float	Fixed::toFloat( void ) const
{
	return (float)this->_value / (1 << Fixed::_bits);
}

int		Fixed::toInt( void ) const
{
	return this->_value >> Fixed::_bits;
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return ((Fixed &)a);
	else
		return ((Fixed &)b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return ((Fixed &)a);
	else
		return ((Fixed &)b);
}

bool	Fixed::operator>(const Fixed &other) const
{
	return (this->_value > other.getRawBits());
}

bool	Fixed::operator<(const Fixed &other) const
{
	return (this->_value < other.getRawBits());
}

bool	Fixed::operator<=(const Fixed &other) const
{
	return (this->_value <= other.getRawBits());
}

bool	Fixed::operator>=(const Fixed &other) const
{
	return (this->_value >= other.getRawBits());
}

bool	Fixed::operator==(const Fixed &other) const
{
	return (this->_value == other.getRawBits());
}

bool	Fixed::operator!=(const Fixed &other) const
{
	return (this->_value != other.getRawBits());
}

Fixed	Fixed::operator+(const Fixed &other) const
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &other) const
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &other) const
{
	return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);
	this->_value++;
	return (tmp);
}

Fixed	&Fixed::operator++(void)
{
	(this->_value)++;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);
	(this->_value)--;
	return (tmp);
}

Fixed	&Fixed::operator--(void)
{
	(this->_value)--;
	return (*this);
}

std::ostream & operator<<(std::ostream & o, const Fixed &copy)
{
	o << copy.toFloat();
	return (o);
}
