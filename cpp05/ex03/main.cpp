#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	Bureaucrat a("Bureaucrat", 1);
	Bureaucrat b("Bureaucrat", 150);
	ShrubberyCreationForm sform("Garden");
	RobotomyRequestForm   rform("Human");
	PresidentialPardonForm pform("Prisoner");
	std::cout << std::endl;
	try
	{
		b.signForm(sform);
		b.signForm(rform);
		a.signForm(sform);
		a.signForm(rform);
		a.signForm(pform);
		a.executeForm(sform);
		a.executeForm(rform);
		a.executeForm(pform);
		b.executeForm(sform);
		b.executeForm(rform);
		b.executeForm(pform);
		b.signForm(pform);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	return 0;
}