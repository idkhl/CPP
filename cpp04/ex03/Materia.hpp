#ifndef MATERIA_HPP
# define MATERIA_HPP
# include <iostream>
# include "Character.hpp"

class AMateria
{
	protected:

	public:
		AMateria(std::string const & type);

	std::string const & getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif