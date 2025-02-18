#include "Dog.hpp"

Dog::Dog() : Animal() {
	std::cout << "Dog constructor called" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog& other) : Animal(other){
	*this = other;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog& other) {
	if (this != &other)
	{
        this->type = other.getType();
    }
	std::cout << "Dog assignation operator called" << std::endl;
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

std::string Dog::getType() const
{
	return (this->type);
}

void Dog::makeSound() const
{
	std::cout << "  OUAF OUAF" << std::endl;
}