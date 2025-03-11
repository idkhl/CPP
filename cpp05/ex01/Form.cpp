#include "Bureaucrat.hpp"
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
}

Form::Form(const Form &copy):
	_name(copy.getName()),
	_signed(copy.getSigned()),
	_signGrade(copy.getSignGrade()),
	_execGrade(copy.getExecGrade()) {
	std::cout << "Form copy constructor called" << std::endl;
}

Form &Form::operator=(Form const &copy) {

}