#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include <iostream>
# include "Materia.hpp"

class ICharacter
{
	private:
		// AMateria inventory;
		std::string _name;

	public:
		ICharacter(std::string name);
		ICharacter(ICharacter const &copy);
		ICharacter &operator=(ICharacter const &copy);
		virtual ~ICharacter() {}
		
	virtual std::string const & getName() const = 0;
	virtual void equip(AMateria* m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;
};

#endif