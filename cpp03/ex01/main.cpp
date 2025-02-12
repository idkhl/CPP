#include "ClapTrap.hpp"

int main()
{
	ClapTrap clap1("Lili");
    ClapTrap clap2("Lala");

    std::cout << std::endl;

    clap1.attack("Lala");
    clap2.takeDamage(3);

    std::cout << std::endl;

    clap2.beRepaired(5);

    std::cout << std::endl;

    for (int i = 0; i < 11; i++) {
        clap1.attack("Lala");
    }

    std::cout << std::endl;

    return 0;
}