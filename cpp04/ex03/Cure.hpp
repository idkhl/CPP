#ifndef CURE_HPP
# define CURE_HPP
# include "Materia.hpp"

// class AMateria;
// class Materia;
// class ICharacter;

class Cure : public AMateria
{
	public:
		Cure();
        Cure(const Cure &copy);
        Cure &operator=(const Cure &copy);
        ~Cure();

	AMateria* clone() const;
	void use(ICharacter &target);
};

#endif