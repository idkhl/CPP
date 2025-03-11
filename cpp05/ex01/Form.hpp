#ifndef FORM_HPP
# define FORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string _name;
		bool 		_signed;
		int	const	_signGrade;
		int	const	_execGrade;

	public:
		Form();
		~Form();
		Form(std::string name, int const signGrade, int const signExec);
		Form(const Form &copy);
		Form &operator=(const Form &copy);

	void getName() const;
	void getSigned();
	void getSignGrade();
	void getExecGrade();
	void beSigned(Bureaucrat &bureaucrat);

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs);

#endif