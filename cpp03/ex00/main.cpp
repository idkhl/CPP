#include "ClapTrap.hpp"

int main()
{
    ClapTrap clap1("Lili");
    ClapTrap clap2("Lala");
    
    clap1.attack("a target");
    clap2.attack("an enemy");
    
    clap1.takeDamage(5);
    clap1.beRepaired(3);
    clap1.takeDamage(8);
    clap1.beRepaired(5);
    
    for (int i = 0; i < 10; ++i) {
        clap2.attack("a random target");
    }
    clap2.attack("a random target");
    
    return 0;
}