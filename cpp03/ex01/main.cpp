#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    ClapTrap clap("Lili");
    ScavTrap scav("Lala");

    clap.attack("an ennemy");
    scav.attack("another ennemy");

    clap.takeDamage(5);
    scav.takeDamage(30);

    clap.beRepaired(3);
    scav.beRepaired(10);

    scav.guardGate();

    return 0;
}
