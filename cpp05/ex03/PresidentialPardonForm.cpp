#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("Presidential Pardon Form", 25, 5), _target("default") {
    std::cout << "Presidential Pardon Form default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("Presidential Pardon Form", 25, 5), _target(target) {
    std::cout << "Presidential Pardon Form has been created regarding " << this->_target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy): AForm(copy), _target(copy.getTarget()) {
    std::cout << "Presidential Pardon Form copy constructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy) {
    std::cout << "Presidential Pardon Form assignment operator called" << std::endl;
    if (this != &copy) {
        AForm::operator=(copy);
        this->_target = copy.getTarget();
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "Presidential Pardon Form destructor called" << std::endl;
}  

std::string	PresidentialPardonForm::getTarget(void) const
{
    return _target;
}

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
    if (executor.getGrade() > this->getExecGrade())
        throw GradeTooLowException();
    if (this->getSigned() == false)
        throw IsNotSigned();
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

