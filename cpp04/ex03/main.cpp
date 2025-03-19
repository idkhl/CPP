#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("Mob");

    me->equip(src->createMateria("ice"));
    me->equip(src->createMateria("cure"));

    ICharacter* bob = new Character("Bob");

    me->use(0, *bob);
    me->use(1, *bob);

    std::cout << std::endl;

    me->unequip(0);
    me->use(0, *bob);

    me->equip(src->createMateria("ice"));
    me->equip(src->createMateria("cure"));
    me->equip(src->createMateria("ice"));
    me->equip(src->createMateria("cure")); 
    AMateria* unknown = src->createMateria("fire");
    if (!unknown)
        std::cout << "Unknown materia could not be created" << std::endl;
    me->unequip(0);
    me->unequip(1);
    me->unequip(2);
    me->unequip(3);
    me->equip(src->createMateria("cure"));
    me->equip(src->createMateria("ice"));
    me->equip(src->createMateria("cure"));
    me->equip(src->createMateria("ice"));
    me->unequip(0);
    me->unequip(1);
    me->unequip(2);
    me->unequip(3);

    delete bob;
    delete me;
    delete src;

    return 0;
}