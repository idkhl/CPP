#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		std::string _name;
		int	_hit;
		int _energy;
		int _damage;

	public:
		ScavTrap(const std::string name);
		ScavTrap(const ScavTrap& other);
		ScavTrap &operator=(const ScavTrap& other);
		~ScavTrap();

	void guardGate();
};


#endif