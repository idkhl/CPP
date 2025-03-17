#include "AForm.hpp"

AForm::AForm(): _name("default"), _signed(false), _signGrade(1), _execGrade(1) {
	std::cout << "Form default constructor called" << std::endl;
}

AForm::~AForm() {
	std::cout << "Form destructor called" << std::endl;
}

AForm::AForm(std::string name, int signGrade, int execGrade): _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade) {
	if (signGrade < 1 || execGrade < 1)
		throw AForm::GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw AForm::GradeTooLowException();
	std::cout << "Form " << _name << " constructor called" << std::endl;
}

AForm::AForm(const AForm &copy): _name(copy._name), _signed(copy._signed), _signGrade(copy._signGrade), _execGrade(copy._execGrade) {
	std::cout << "Form " << _name << " copy constructor called" << std::endl;
}

AForm &AForm::operator=(AForm const &copy) {
	if (this != &copy)
		_signed = copy._signed;
	std::cout << "Form " << _name << " operator constructor called" << std::endl;
	return *this;
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (_signed)
		throw IsNotSigned();
	if (bureaucrat.getGrade() > _signGrade)
		throw AForm::GradeTooLowException();
	_signed = true;
	// std::cout << bureaucrat.getName() << " signed " << _name << std::endl;
}

const std::string	AForm::getName(void) const
{
	return _name;
}

int	AForm::getExecGrade(void) const
{
	return _execGrade;
}

int	AForm::getSignGrade(void) const
{
	return _signGrade;
}

bool	AForm::getSigned(void) const
{
	return _signed;
}

void	AForm::execute(Bureaucrat const & executor) const
{
	if (this->_signed == false)
		return (throw IsNotSigned());
	if (executor.getGrade() > _signGrade)
		throw AForm::GradeTooLowException();
	this->execute(executor);
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("grade too high");
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return ("grade too low");
}

const char*	AForm::IsNotSigned::what() const throw()
{
	return ("Form is already signed");
}

std::ostream&	operator<<(std::ostream& o, const AForm& form)
{
	o << "Form name is " << form.getName() << std::endl;
	o << "Form execution grade is " << form.getExecGrade() << std::endl;
	o << "Form sign grade is " << form.getSignGrade() << std::endl;
	o << "Is form signed : ";
	form.getSigned() ? o << "Yes\n" : o << "No\n";
	return o;
}