#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure (Cure const &copy) : AMateria(copy) {}

Cure &Cure::operator=(Cure const &copy) {
	if (this != &copy)
		this->_type = copy._type;
	return *this;
}

Cure::~Cure() {}

AMateria*  Cure::clone() const
{
	return (new Cure());
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals  " << target.getName() << "'s wounds *" << std::endl;
}