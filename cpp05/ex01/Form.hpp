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
		Form(std::string name, int const signGrade, int const execGrade);
		Form(const Form &copy);
		Form &operator=(const Form &copy);

	const std::string getName() const;
	bool getSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;
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

	class AlreadySigned : public std::exception
	{
		public:
			const char	*what(void) const throw();
	};
};

std::ostream& operator<<(std::ostream & o, Form const & rhs);

#endif