#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	std::cout << "WrongCat constructor called" << std::endl;
	this->type = "Wrong Cat";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
	*this = other;
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat& other) {
	std::cout << "WrongCat assignation operator called" << std::endl;
	if (this != &other)
	{
        this->type = other.getType();
    }
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}

std::string WrongCat::getType() const
{
	return (this->type);
}

void WrongCat::makeSound() const
{
	std::cout << "  UUUUOAIM" << std::endl;
}
