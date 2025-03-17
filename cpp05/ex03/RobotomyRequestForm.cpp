#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("Robotomy Request Form", 72, 45), _target("default") {
	std::cout << "Robotomy Request Form default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("Robotomy Request Form", 72, 45) {
	this->_target = target;
	std::cout << "Robotomy Request Form has been created regarding " << this->_target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm("Robotomy Request Form", 25, 5), _target(copy.getTarget()) {
	std::cout << "Robotomy Request Form copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy) {
	std::cout << "Robotomy Request Form assignment operator called" << std::endl;
	(void)copy;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Robotomy Request Form destructor called" << std::endl;
}

std::string RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	std::srand(std::time(NULL));
	if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
	if (this->getSigned() == false)
		throw IsNotSigned();
	std::cout << "* BZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ *" << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << _target << "'s robotomy failed" << std::endl;
}
