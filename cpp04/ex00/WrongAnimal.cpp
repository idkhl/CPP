#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Wrong Animal") {
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
	*this = other;
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal& other) {
	if (this != &other)
	{
        type = other.getType();
    }
	std::cout << "WrongAnimal assignation operator called" << std::endl;
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}

void WrongAnimal::makeSound() const
{
	std::cout << "  *weird sound*" << std::endl;
}