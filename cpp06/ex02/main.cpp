#include "Base.hpp"
#include "Classes.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

Base	*generate(void)
{
	std::srand(std::time(NULL));
	int type = std::rand() % 3;
	Base *ptr = NULL;
	switch (type)
	{
		case 0:
			std::cout << "A created\n";
			ptr = new A();
			break;
		case 1:
			std::cout << "B created\n";
			ptr = new B();
			break;
		case 2:
			std::cout << "C created\n";
			ptr = new C();
			break;
		default:
			break;
	}
	return ptr;
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "It is A\n";
	else if (dynamic_cast<B *>(p))
		std::cout << "It is B\n";
	else if (dynamic_cast<C *>(p))
		std::cout << "It is C\n";
}

void	identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "It is a A\n";
	}
	catch (...)
	{
		try
		{
			B& b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << "It is a B\n";
		}
		catch (...)
		{
			try
			{
				C& c = dynamic_cast<C&>(p);
				(void)c;
				std::cout << "It is a C\n";
			}
			catch (...) {}
		}
	}
}

int main() {
	Base *base = generate();
	identify(base);
	identify(*base);
	delete base;
	return 0;
}