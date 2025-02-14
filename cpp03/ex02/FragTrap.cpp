#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string name) : ClapTrap(name) {
	this->_name = name;
	this->_hit = 100;
	this->_energy = 100;
	this->_damage = 30;
	std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	*this = other;
	std::cout << "FragTrap " << _name << " copied" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap& other) {
	if (this != &other)
	{
        _name = other._name;
        _hit = other._hit;
        _energy = other._energy;
        _damage = other._damage;
    }
	std::cout << "FragTrap " << _name << " assigned" << std::endl;
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << this->_name << " high fives everyone!" << std::endl;
}