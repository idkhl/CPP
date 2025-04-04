#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v;
	for (int i = 4; i < 10; i++)
		v.push_back(i);
	try
	{
		std::vector<int>::const_iterator it = easyfind(v, 3);
		std::cout << *it << "\n";
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::vector<int>::const_iterator it = easyfind(v, 5);
		std::cout << *it << "\n";
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}