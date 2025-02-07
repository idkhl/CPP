#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int number) {
	std::cout << "Int constructor called" << std::endl;
	_value = number << _bits;
}

Fixed::Fixed(const float fnumber) {
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(fnumber * (1 << _bits));
}

Fixed::Fixed(const Fixed &copy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed &Fixed::operator=(const Fixed &copy) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = copy.getRawBits();
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
    return this->_value;
}

void Fixed::setRawBits (int const raw)
{
    // std::cout << "setRawBits member function called" << std::endl;
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

std::ostream & operator<<(std::ostream & o, const Fixed &copy)
{
	o << copy.toFloat();
	return (o);
}