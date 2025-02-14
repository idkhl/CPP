#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string name): ClapTrap(name) {
	this->_name = name;
	this->_hit = 100;
	this->_energy = 50;
	this->_damage = 20;
	std::cout << "ScavTrap constructor called" << std::endl;
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
	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (_hit <= 0) {
        std::cout << "ScavTrap " << _name << " has no hit points left to attack!" << std::endl;
        return;
    }
    if (_energy <= 0) {
        std::cout << "ScavTrap " <<_name << " has no energy left to attack!" << std::endl;
        return;
    }
    std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _damage << " points of damage!" << std::endl;
    _energy--;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode" << std::endl;
}
