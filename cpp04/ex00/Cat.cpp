#include "Cat.hpp"

Cat::Cat() : Animal() {
	std::cout << "Cat constructor called" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat& other) : Animal(other) {
	*this = other;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat& other) {
	std::cout << "Cat assignation operator called" << std::endl;
	if (this != &other)
	{
        this->type = other.getType();
    }
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

std::string Cat::getType() const
{
	return (this->type);
}

void Cat::makeSound() const
{
	std::cout << "  MIAOUUUU" << std::endl;
}
