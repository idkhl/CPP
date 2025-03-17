#ifndef INTERN_HPP
# define INTERN_HPP
# include <iostream>
# include "AForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);
		~Intern();

	AForm *makeForm(const std::string name, const std::string target) const;

	class	FormDoesNotExist : public std::exception
	{
		public:
			const char	*what(void) const throw();
	};
};

#endif