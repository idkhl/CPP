#include "Materia.hpp"

AMateria::AMateria() : _type(NULL) {}

AMateria::AMateria(std::string const &type) {

}

AMateria::AMateria(AMateria const &copy) {}

AMateria &AMateria::operator=(AMateria const &copy) {}

AMateria::~AMateria() {}

std::string const & AMateria::getType() const
{
	return this->_type;
}

AMateria* AMateria::clone() const
{

}

void use(ICharacter& target)
{
	
}
