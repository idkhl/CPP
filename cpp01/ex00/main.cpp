#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int	main()
{
	Zombie* zombie;

	zombie = newZombie("Nono");
	randomChump("Nini");
	delete zombie;
}