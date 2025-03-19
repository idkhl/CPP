#include "Character.hpp"

Character::Character(std::string const &name) : _name(name) {
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
    for (int i = 0; i < 5; i++)
        _floor[i] = NULL;
}

Character::Character(const Character &other) : _name(other._name) {
    for (int i = 0; i < 4; i++)
	{
        if (other._inventory[i])
            _inventory[i] = other._inventory[i]->clone();
        else
            _inventory[i] = NULL;
    }
    for (int i = 0; i < 5; i++)
    {
        if (other._floor[i])
            _floor[i] = other._floor[i]->clone();
        else
            _floor[i] = NULL;
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
        for (int i = 0; i < 5; i++)
        {
            delete _floor[i];
            _floor[i] = (other._floor[i]) ? other._floor[i]->clone() : NULL;
        }
    }
    return *this;
}

Character::~Character() {
    for (int i = 0; i < 4; i++)
        delete _inventory[i];
    deleteFloor();
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
        addToFloor(_inventory[idx]);
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

void Character::addToFloor(AMateria *materia)
{
    int i;
    for (i = 0 ; i < 5 ; i++)
		if (_floor[i] == NULL)
			break;
	if (i == 5)
	{
		deleteFloor();
		_floor[0] = materia;
	}
	else
		_floor[i] = materia;
}

void	Character::deleteFloor(void)
{
	for (int i = 0 ; i < 5 ; i++)
	{
		if (_floor[i])
		{
			delete _floor[i];
			_floor[i] = NULL;
		}
	}
}