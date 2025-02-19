#include "Dog.hpp"

Dog::Dog() : Animal() {
	std::cout << "Dog constructor called" << std::endl;
	this->type = "Dog";
	this->_brain = new(std::nothrow) Brain;
}

Dog::Dog(const Dog& other) : Animal(other){
	this->_brain = NULL;
	*this = other;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog& other) {
	std::cout << "Dog assignation operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		delete this->_brain; 
		this->_brain = new Brain(*other._brain);
        this->type = other.getType();
    }
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete this->_brain;
}

std::string Dog::getType() const
{
	return (this->type);
}

void Dog::makeSound() const
{
	std::cout << "  OUAF OUAF" << std::endl;
}