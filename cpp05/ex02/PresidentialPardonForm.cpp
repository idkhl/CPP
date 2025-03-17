#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("Presidential Pardon Form", 25, 5), _target("default") {
	std::cout << "Presidential Pardon Form default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("Presidential Pardon Form", 25, 5) {
	this->_target = target;
	std::cout << this->_name << " has been created regarding " << this->_target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy): AForm("Presidential Pardon Form", 25, 5), _target(copy.getTarget()) {
	std::cout << "Presidential Pardon Form copy constructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy) {
	(void)copy;
	return *this;
}

std::string	PresidentialPardonForm::getTarget(void) const
{
	return _target;
}

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
	if (this->getSigned() == true)
		throw IsNotSigned();
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

