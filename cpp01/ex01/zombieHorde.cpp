#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie* zmb = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		zmb[i].set_name(name);
		zmb[i].announce();
	}
	return (&zmb[0]);
}