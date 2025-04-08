#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main()
{
	try
	{
		Span shortSpan(5);

		std::srand(std::time(0));
		std::vector<int> numbers;
		for (int i = 0; i < 5; ++i)
			numbers.push_back(std::rand() % 50);
		
		shortSpan.addNumbers(numbers.begin(), numbers.end());
		std::cout << "Added numbers: ";
		for (size_t i = 0; i < numbers.size(); ++i)
			std::cout << numbers[i] << " ";
		std::cout << std::endl;

		std::cout << shortSpan.shortestSpan() << " is the shortest span" << std::endl;
		std::cout << shortSpan.longestSpan() << " is the longest span" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}