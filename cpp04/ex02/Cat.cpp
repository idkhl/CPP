#include "Cat.hpp"

Cat::Cat() : Animal() {
	std::cout << "Cat constructor called" << std::endl;
	this->type = "Cat";
	this->_brain = new(std::nothrow) Brain;
}

Cat::Cat(const Cat& other) : Animal(other) {
	this->_brain = NULL;
	*this = other;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat& other) {
	std::cout << "Cat assignation operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		delete this->_brain; 
		this->_brain = new Brain(*other._brain);
		this->type = other.getType();
	}
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete this->_brain;
}

std::string Cat::getType() const
{
	return (this->type);
}

void Cat::makeSound() const
{
	std::cout << "  MIAOUUUU" << std::endl;
}
