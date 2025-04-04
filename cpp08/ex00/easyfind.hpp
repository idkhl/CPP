#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <exception>
# include <vector>

template <typename T>
typename T::const_iterator easyfind(T &tab, int i);

class IntNotFound : public std::exception
{
	const char* what() const throw() {
		return "Int is not in the array";
	}
};

# include "easyfind.tpp"

#endif