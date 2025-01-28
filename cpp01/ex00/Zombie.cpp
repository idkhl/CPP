#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name) {
	std::cout << "New zombie created, welcome " << this->_name << std::endl;
	return;
}

Zombie::~Zombie() {
	std::cout << "Bye bye " << this->_name << std::endl;
}

void Zombie::announce()
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}