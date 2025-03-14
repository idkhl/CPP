#include "Form.hpp"

Form::Form(): _name("default"), _signed(false), _signGrade(1), _execGrade(1) {
	std::cout << "Form default constructor called" << std::endl;
}

Form::~Form() {
	std::cout << "Form destructor called" << std::endl;
}

Form::Form(std::string name, int signGrade, int execGrade): _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade) {
	if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
	std::cout << "Form " << _name << " constructor called" << std::endl;
}

Form::Form(const Form &copy): _name(copy._name), _signed(copy._signed), _signGrade(copy._signGrade), _execGrade(copy._execGrade) {
	std::cout << "Form " << _name << " copy constructor called" << std::endl;
}

Form &Form::operator=(Form const &copy) {
	if (this != &copy)
		_signed = copy._signed;
	std::cout << "Form " << _name << " operator constructor called" << std::endl;
	return *this;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (_signed)
		throw AlreadySigned();
	if (bureaucrat.getGrade() > _signGrade)
		throw Form::GradeTooLowException();
	_signed = true;
	// std::cout << bureaucrat.getName() << " signed " << _name << std::endl;
}

const std::string	Form::getName(void) const
{
	return _name;
}

int	Form::getExecGrade(void) const
{
	return _execGrade;
}

int	Form::getSignGrade(void) const
{
	return _signGrade;
}

bool	Form::getSigned(void) const
{
	return _signed;
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("grade too high");
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("grade too low");
}

const char*	Form::AlreadySigned::what() const throw()
{
	return ("Form is already signed");
}

std::ostream&	operator<<(std::ostream& o, const Form& form)
{
	o << "Form name is " << form.getName() << std::endl;
	o << "Form execution grade is " << form.getExecGrade() << std::endl;
	o << "Form sign grade is " << form.getSignGrade() << std::endl;
	o << "Is form signed : ";
	form.getSigned() ? o << "Yes\n" : o << "No\n";
	return o;
}