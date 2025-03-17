#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	Bureaucrat a("bureaucrat", 1);
	ShrubberyCreationForm sform;
	RobotomyRequestForm   rform;
	PresidentialPardonForm pform;
	try
	{
		a.signForm(sform);
		a.signForm(rform);
		a.signForm(pform);
		a.executeForm(sform);
		a.executeForm(rform);
		a.executeForm(pform);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}