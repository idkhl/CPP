#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	try
	{
		Bureaucrat a("Bureaucrat", 1);
		Bureaucrat b("Bureaucrat", 150);
		Intern intern;
		AForm *sform = intern.makeForm("shrubbery creation", "Garden");
		AForm *rform = intern.makeForm("robotomy request", "Human");
		AForm *pform = intern.makeForm("presidential pardon", "Prisoner");
		// AForm *tform = intern.makeForm("coucou", "Prisoner");
		std::cout << std::endl;
		// b.signForm(*tform);
		b.signForm(*sform);
		b.signForm(*rform);
		std::cout << std::endl;
		a.signForm(*sform);
		a.signForm(*rform);
		a.signForm(*pform);
		a.executeForm(*sform);
		a.executeForm(*rform);
		a.executeForm(*pform);
		std::cout << std::endl;
		b.executeForm(*sform);
		b.executeForm(*rform);
		b.executeForm(*pform);
		b.signForm(*pform);
		std::cout << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}