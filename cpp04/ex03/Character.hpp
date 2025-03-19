#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include <iostream>
# include "Materia.hpp"

class	AMateria;

class ICharacter
{
	public:
		virtual ~ICharacter() {}
	
	virtual std::string const & getName() const = 0;
	virtual void equip(AMateria* m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;
};

class Character : public ICharacter
{
	private:
		std::string _name;
		AMateria *_inventory[4];
		AMateria *_floor[5];

	public:
		Character(std::string const &name);
		Character(Character const &copy);
		Character &operator=(Character const &copy);
		~Character();

		std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
		void addToFloor(AMateria *materia);
		void deleteFloor(void);
};

#endif