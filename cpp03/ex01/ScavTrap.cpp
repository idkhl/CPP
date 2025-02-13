#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string name): ClapTrap(name) {
	std::cout << "Constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other) {
	*this = other;
	std::cout << "ScavTrap " << _name << " copied" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap& other) {
	if (this != &other)
	{
        _name = other._name;
        _hit = other._hit;
        _energy = other._energy;
        _damage = other._damage;
    }
	std::cout << "ScavTrap " << _name << " assigned" << std::endl;
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "Destructor called" << std::endl;
}

