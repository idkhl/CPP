#ifndef ICE_HPP
# define ICE_HPP
# include "Materia.hpp"

// class ICharacter;
// class AMateria;

class Ice : public AMateria
{
	public:
		Ice();
		Ice(Ice const &copy);
		Ice &operator=(Ice const &copy);
		~Ice();

	AMateria*  clone() const;
	void use(ICharacter &target);
};

#endif