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

void AMateria::use(ICharacter& target)
{
	(void)target;
// std::cout << "* uses " << _type << " on " << target.getName() << " *" << std::endl;
}
