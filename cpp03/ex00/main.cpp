#include "ClapTrap.hpp"

int main()
{
	ClapTrap clap("Lala");

	clap.attack("Lolo");
	clap.beRepaired(20);
	clap.takeDamage(12);
	clap.attack("Lili");
	clap.beRepaired(100);
}