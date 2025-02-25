#ifndef ICE_HPP
# define ICE_HPP
# include "Character.hpp"

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