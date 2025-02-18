#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _weapon() {
	_name = name;
}

HumanB::~HumanB() {}

void	HumanB::attack()
{
	if (_weapon)
		std::cout << _name << " attacks with " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " attacks without any weapon " << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon) {
	_weapon = &weapon;
}