#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main()
{
	std::vector<int> v;
	for (int i = 4; i < 10; i++)
		v.push_back(i);
	try
	{
		std::cout << *easyfind(v, 6) << "\n";
		std::cout << *easyfind(v, 3) << "\n";
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::list<int> emptyList;
	try
	{
		easyfind(emptyList, 1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::vector<int> duplicates;
	for (int i = 4; i < 10; i++)
		duplicates.push_back(i);
	duplicates.push_back(3);
	try
	{
		std::cout << *easyfind(duplicates, 3) << "\n";
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}