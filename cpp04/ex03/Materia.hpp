#ifndef MATERIA_HPP
# define MATERIA_HPP
# include <iostream>
// # include "Character.hpp"
# include "Cure.hpp"

class ICharacter;
class Character;

class AMateria
{
	protected:
		std::string _type;

	public:
		AMateria();
		AMateria(std::string const & type);
		AMateria(AMateria const &copy);
		AMateria &operator=(AMateria const &copy);
		virtual ~AMateria();

	std::string const & getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif