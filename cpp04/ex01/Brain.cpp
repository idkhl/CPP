#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &other) {
	std::cout << "Brain copy constructor called" << std::endl;
	*this = other;
}

Brain &Brain::operator=(const Brain &other) {
	std::cout << "Brain assignation operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0 ; i < 100; i++)
		{
			ideas[i] = other.ideas[i];
		}
    }
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}