#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main()
{
	int nb;
	std::string name;
	Zombie* myZombie;

	nb = 3;
	name = "coucou";
	myZombie = zombieHorde(nb, name);
	delete [] myZombie;

	nb = 3;
	name = "coucou";
	myZombie = zombieHorde(nb, name);
	delete [] myZombie;

}