#include "Fixed.hpp"

Fixed::Fixed() : number(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=

