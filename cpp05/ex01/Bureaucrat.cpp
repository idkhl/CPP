#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("No name"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy): _name(copy.getName()), _grade(copy.getGrade()) {
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy) {
	this->_grade = copy.getGrade();
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

void Bureaucrat::incrementGrade()
{
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade -= 1;
}

void Bureaucrat::decrementGrade()
{
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade += 1;
}

void	Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
	
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade Too High");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low");
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &other)
{
	o << other.getName() << ", bureaucrat grade " <<  other.getGrade() << "." << std::endl;
	return (o);
}

