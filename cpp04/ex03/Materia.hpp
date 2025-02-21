#ifndef MATERIA_HPP
# define MATERIA_HPP
# include <iostream>
# include "Character.hpp"
# include "Cure.hpp"

class AMateria
{
	protected:
		Ice ice;
		Cure cure;

	public:
		AMateria(std::string const & type);
		AMateria();
		AMateria(AMateria const &copy);
		AMateria operator=(AMateria const &copy);
		~AMateria();

	std::string const & getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif