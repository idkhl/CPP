#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
    (void)this->_bits;
	std::cout << "Default constructor called" << std::endl;
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
	std::cout << "getRawBits member function called" << std::endl;
    return this->_value;
}

void Fixed::setRawBits (int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_value = raw;
}