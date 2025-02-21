#ifndef ICE_HPP
# define ICE_HPP
# include "Character.hpp"

class Ice
{
	public:
		Ice();
		Ice(Ice const &copy);
		Ice operator=(Ice const &copy);
		~Ice();

	Ice  clone();
	void use(ICharacter&);
};

#endif