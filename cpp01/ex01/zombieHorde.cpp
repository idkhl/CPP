#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	if (name == "")
	{
		std::cout << "Error: zombie horde has no name" << std::endl;
		return (NULL);
	}
	if (N > std::numeric_limits<int>::max() || N < 0)
	{
		std::cout << "Error: couldn't allocate zombie horde" << std::endl;
		return (NULL);
	}
	Zombie* zmb = new(std::nothrow) Zombie[N];
	if (!zmb)
	{
		std::cout << "Error: couldn't allocate zombie horde" << std::endl;
		return (NULL);
	}
	for (int i = 0; i < N; i++)
	{
		zmb[i].set_name(name);
		zmb[i].announce();
	}
	return (&zmb[0]);
}