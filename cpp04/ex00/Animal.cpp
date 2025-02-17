#include "Animal.hpp"

Animal::Animal() : _type(NULL) {
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal& other) {
	*this = other;
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal& other) {
	if (this != &other)
	{
        _type = other._type;
    }
	std::cout << "Animal " << _type << " assigned" << std::endl;
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

Dog::Dog() {
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& other) {
	*this = other;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog& other) {
	if (this != &other)
	{
        _type = other._type;
    }
	std::cout << "Dog " << _type << " assigned" << std::endl;
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

Cat::Cat() {
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& other) {
	*this = other;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat& other) {
	if (this != &other)
	{
        _type = other._type;
    }
	std::cout << "Cat " << _type << " assigned" << std::endl;
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

std::string Animal::getType()
{

}

std::ostream & operator<<(std::ostream & o, const Animal &copy)
{
	o << copy.getType();
	return (o);
}