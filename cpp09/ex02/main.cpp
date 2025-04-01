#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cerr << "Format: ./PmergeMe 1 2 3 4 5" << std::endl;
		return 1;
	}
	std::cout << "Before: ";
	for (int i = 1; i < ac; i++)
		std::cout << av[i] << " ";
	std::cout << std::endl;
}