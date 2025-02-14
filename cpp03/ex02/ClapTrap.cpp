#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string name): _name(name), _hit(10), _energy(10), _damage(0) {
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	*this = other;
	std::cout << "ClapTrap " << _name << " copied" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap& other) {
	if (this != &other)
	{
        _name = other._name;
        _hit = other._hit;
        _energy = other._energy;
        _damage = other._damage;
    }
	std::cout << "ClapTrap " << _name << " assigned" << std::endl;
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (_hit <= 0) {
        std::cout << "ClapTrap " << _name << " has no hit points left to attack!" << std::endl;
        return;
    }
    if (_energy <= 0) {
        std::cout << "ClapTrap " <<_name << " has no energy left to attack!" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _damage << " points of damage!" << std::endl;
    _energy--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hit <= 0) {
        std::cout << "ClapTrap " << _name << " is already down!" << std::endl;
        return;
    }
    _hit -= amount;
    if (_hit < 0)
        _hit = 0;
    std::cout << "ClapTrap " << _name << " took " << amount << " damage! Remaining: " << _hit << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hit <= 0) {
        std::cout << "ClapTrap " << _name << " cannot repair, it's out of HP!" << std::endl;
        return;
    }
    if (_energy <= 0) {
        std::cout << "ClapTrap " << _name << " has no energy left to repair!" << std::endl;
        return;
    }
    _hit += amount;
    _energy--;
    std::cout << "ClapTrap " << _name << " repaired itself, gaining " << amount << " hit points! Remaining HP: " << _hit << std::endl;
}