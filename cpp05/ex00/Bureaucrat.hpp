#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>

class Bureaucrat
{
	private:
		const std::string _name;
		int			_grade;

	public:
		Bureaucrat();
		~Bureaucrat();

		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat &operator=(const Bureaucrat &copy);

	std::string	getName(void) const;
	int			getGrade(void) const;
	void		incrementGrade(void);
	void		decrementGrade(void);

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

std::ostream &operator<<(std::ostream & o, Bureaucrat const & rhs);

#endif