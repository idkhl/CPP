#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	try
	{
		Bureaucrat a("Bureaucrat1", 1);
		Bureaucrat b("Bureaucrat150", 150);
		ShrubberyCreationForm sform("Garden");
		RobotomyRequestForm   rform("Human");
		PresidentialPardonForm pform("Prisoner");
		std::cout << std::endl;
		b.signForm(sform);
		b.signForm(rform);
		a.executeForm(sform);
		std::cout << std::endl;
		a.signForm(sform);
		a.signForm(rform);
		a.signForm(pform);
		a.executeForm(sform);
		a.executeForm(rform);
		a.executeForm(pform);
		std::cout << std::endl;
		b.executeForm(sform);
		b.executeForm(rform);
		b.executeForm(pform);
		b.signForm(pform);
		std::cout << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}