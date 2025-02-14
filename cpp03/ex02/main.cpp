#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    ClapTrap clap("Lili");
    ScavTrap scav("Lala");
    FragTrap frag("Lulu");
    std::cout << std::endl;

    clap.attack("an ennemy");
    scav.attack("another ennemy");
    frag.attack("more ennemies");

    clap.takeDamage(5);
    scav.takeDamage(30);
    frag.takeDamage(40);

    clap.beRepaired(3);
    scav.beRepaired(10);
    frag.beRepaired(15);

    scav.guardGate();
    frag.highFivesGuys();

    std::cout << std::endl;
    return 0;
}
