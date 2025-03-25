#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v;
	for (int i = 0; i < 10; i++)
		v.push_back(i);
	try
	{
		std::vector<int>::iterator it = easyfind(v, 1);
		std::cout << *it << "\n";
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}