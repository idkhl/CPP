#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other) {
	(void)other;
}

Intern &Intern::operator=(const Intern &other) {
	(void)other;
	return (*this);
}

Intern::~Intern() {}

AForm	*Intern::makeForm(const std::string name, const std::string target) const
{
	std::string forms[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int i;
	AForm *form = NULL;
	for (i = 0 ; i < 3 ; i++)
	{
		if (name == forms[i])
			break;
	}
	switch (i)
	{
		case 0:
			form = new ShrubberyCreationForm(target);
			break;
		case 1:
			form = new RobotomyRequestForm(target);
			break;
		case 2:
			form = new PresidentialPardonForm(target);
			break;
		default:
			throw FormDoesNotExist();
			break;
	}
	return form;
}

const char	*Intern::FormDoesNotExist::what(void) const throw()
{
	return "Intern can't create form because it doesn't exist";
}