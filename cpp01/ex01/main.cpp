#include "Zombie.hpp"


Zombie* zombieHorde(int N, std::string name);

int main()
{
	int nb;
	std::string name;
	Zombie* myZombie;

	nb = std::numeric_limits<int>::max() + 1;
	name = "";
	myZombie = zombieHorde(nb, name);
	if (!myZombie)
		return (1);
	delete [] myZombie;

	nb = 3;
	name = "";
	myZombie = zombieHorde(nb, name);
	delete [] myZombie;
	if (!myZombie)
		return (1);
	return (0);
}