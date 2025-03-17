#ifndef AFORM_HPP
# define AFORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	protected:
		std::string _name;
		bool 		_signed;
		int	const	_signGrade;
		int	const	_execGrade;

	public:
		AForm();
		virtual ~AForm();
		AForm(std::string name, int const signGrade, int const execGrade);
		AForm(const AForm &copy);
		AForm &operator=(const AForm &copy);

	const std::string getName() const;
	bool getSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;
	void beSigned(Bureaucrat &bureaucrat);
	virtual void execute(Bureaucrat const &executor) const;

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

	class IsNotSigned : public std::exception
	{
		public:
			const char	*what(void) const throw();
	};
};

std::ostream& operator<<(std::ostream & o, AForm const & rhs);

#endif