#include "Character.hpp"

Character::Character(std::string const &name) : _name(name) {
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
}

Character::Character(const Character &other) : _name(other._name) {
    for (int i = 0; i < 4; i++)
	{
        if (other._inventory[i])
            _inventory[i] = other._inventory[i]->clone();
        else
            _inventory[i] = NULL;
    }
}

Character &Character::operator=(const Character &other) {
    if (this != &other)
	{
        _name = other._name;
        for (int i = 0; i < 4; i++)
		{
            delete _inventory[i];
            _inventory[i] = (other._inventory[i]) ? other._inventory[i]->clone() : NULL;
        }
    }
    return *this;
}

Character::~Character() {
    for (int i = 0; i < 4; i++)
        delete _inventory[i];
}

std::string const & Character::getName() const
{
    return _name;
}

void Character::equip(AMateria* m)
{
    if (!m)
		return;
    for (int i = 0; i < 4; i++)
	{
        if (!_inventory[i])
		{
            _inventory[i] = m;
            std::cout << _name << " equipped " << m->getType() << " at slot " << i << std::endl;
            return;
        }
    }
    delete m;
    std::cout << _name << "'s inventory is full!" << std::endl;
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4 && _inventory[idx])
	{
        std::cout << _name << " unequipped " << _inventory[idx]->getType() << " from slot " << idx << std::endl;
        _inventory[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && _inventory[idx])
        _inventory[idx]->use(target);
	else
        std::cout << _name << " has no materia in slot " << idx << std::endl;
}