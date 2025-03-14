#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include <iostream>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;
		int			execSign;
		int			gradeSign;
	
	public:
		RobotomyRequestForm();
		~RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);
};

#endif