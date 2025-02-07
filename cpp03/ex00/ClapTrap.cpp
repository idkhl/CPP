#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name): _hit(10), _energy(10), _damage(0) {
	this->_name = name;
	std::cout << "Constructor called" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_hit || this->_energy)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_damage << " points of damage!" << std::endl;
		this->_energy--;
	}
	else if (this->_hit == 0)
		std::cout << "Warning: no hit points left!" << std::endl;
	else if (this->_energy == 0)
		std::cout << "Warning: no energy points left!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "Target lost " << amount << " hit points." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hit || this->_energy)
	{
		std::cout << "ClapTrap " << this->_name << " repaired itself and got " << amount << " hit points back." << std::endl;
		this->_energy--;
		this->_hit += amount;
	}
	else if (this->_hit == 0)
		std::cout << "Warning: no hit points left!" << std::endl;
	else if (this->_energy == 0)
		std::cout << "Warning: no energy points left!" << std::endl;
}