#include <algorithm>
#include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T &tab, int i)
{
	typename T::iterator it = std::find(tab.begin(), tab.end(), i);
	if (it == tab.end())
		throw IntNotFound();
	return it;
}