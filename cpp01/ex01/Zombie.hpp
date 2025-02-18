#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <limits>

class Zombie
{
	private:
		std::string _name;

	public:
		Zombie();
		~Zombie();

	void	announce();
	void	set_name(std::string name);
};

#endif