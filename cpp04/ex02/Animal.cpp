#include "Animal.hpp"

Animal::Animal() : type("Animal") {
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal& other) {
	*this = other;
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal& other) {
	if (this != &other)
	{
        type = other.getType();
    }
	std::cout << "Animal assignation operator called" << std::endl;
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const
{
	return (this->type);
}

void Animal::makeSound() const
{
	std::cout << "  *animal sound*" << std::endl;
}