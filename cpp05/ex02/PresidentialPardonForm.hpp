#ifndef PRESIDENTAILPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include <iostream>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;
		int			_execGrade;
		int			_signGrade;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);

	std::string		getTarget(void) const;
	void 			execute(Bureaucrat const & executor) const;
};

#endif