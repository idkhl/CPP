#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include <iostream>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;
		int			_execGrade;
		int			_signGrade;

	public:
		ShrubberyCreationForm();
		~ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm &copy);

};

#endif