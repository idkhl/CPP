#include "Materia.hpp"

AMateria::AMateria() : _type(NULL) {}

AMateria::AMateria(std::string const &type) : _type(type) {}

AMateria::AMateria(AMateria const &copy) : _type(copy._type) {}

AMateria &AMateria::operator=(AMateria const &copy) {
	if (this != &copy)
		_type = copy._type;
	return *this;
}

AMateria::~AMateria() {}

std::string const & AMateria::getType() const
{
	return this->_type;
}

void use(ICharacter& target)
{
	std::cout << "* uses an  on " << target.getName() << " *" << std::endl;
}
