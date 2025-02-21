#include "Ice.hpp"

Ice::Ice() {}

Ice::Ice (Ice const &copy) {}

Ice Ice::operator=(Ice const &copy) {}

Ice::~Ice() {}

Ice  Ice::clone()
{
	Ice ice;
	return ice;
}

void Ice::use(ICharacter&)
{
	std::cout << "*shoots an ice bolt at " << "*" << std::endl;
}