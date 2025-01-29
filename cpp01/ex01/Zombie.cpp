#include "Zombie.hpp"

Zombie::Zombie(void) {
	std::cout << "New zombie created, welcome" << std::endl;
	return;
}

Zombie::~Zombie() {
	std::cout << "Bye bye " << std::endl;
}

void Zombie::set_name(std::string name)
{
	this->_name = name;
}

void Zombie::announce()
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}