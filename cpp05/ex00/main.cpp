#include "Bureaucrat.hpp"

int main()
{
	try
	{
        Bureaucrat b1("Alice", 1);
        std::cout << b1 << std::endl;
        b1.incrementGrade();
    }
	catch (const std::exception &e)
	{
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try
	{
        Bureaucrat b2("Bob", 150);
        std::cout << b2 << std::endl;
        b2.decrementGrade();
    }
	catch (const std::exception &e)
	{
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try
	{
        Bureaucrat b3("Charlie", 151);
    }
	catch (const std::exception &e)
	{
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try
	{
        Bureaucrat b4("Dave", 0);
    }
	catch (const std::exception &e)
	{
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try
	{
        Bureaucrat b5("Eve", 75);
        std::cout << b5 << std::endl;
        b5.incrementGrade();
        std::cout << "After increment: " << b5 << std::endl;
        b5.decrementGrade();
        std::cout << "After decrement: " << b5 << std::endl;
    }
	catch (const std::exception &e)
	{
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}