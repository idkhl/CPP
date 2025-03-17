#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Shrubbery Creation Form", 72, 45), _target("default") {
    std::cout << "Shrubbery Creation Form default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("Shrubbery Creation Form", 72, 45), _target(target) {
    std::cout << this->_name << " has been created regarding " << this->_target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy), _target(copy.getTarget()) {
    std::cout << "Shrubbery Creation Form copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy) {
    std::cout << "Shrubbery Creation Form assignment operator called" << std::endl;
    if (this != &copy) {
        AForm::operator=(copy);
        this->_target = copy.getTarget();
    }
    return *this;
}

std::string ShrubberyCreationForm::getTarget(void) const
{
    return (this->_target);
}

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
    if (this->getSigned() == false)
        throw IsNotSigned();
    if (executor.getGrade() > this->getExecGrade())
        throw GradeTooLowException();
    std::string file_name(_target + "_shrubbery");
    std::ofstream file(file_name.c_str());
    if (!file)
        throw std::runtime_error("Failed to open file");
    file << "ASCII art of a shrubbery" << std::endl;
    file.close();
}