#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPArdonForm", 25, 5), _target("default") {
	std::cout << "Presidential pardon form constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPArdonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy): AForm("PresidentialPardonForm", 25, 5), _target(copy.getTarget()) {
	std::cout << "Presidential pardon form copy constructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy) {
	(void)copy;
	return *this;
}