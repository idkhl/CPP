#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;

	std::cout << "Pushing 5 onto the stack." << std::endl;
	mstack.push(5);
	std::cout << "Pushing 17 onto the stack." << std::endl;
	mstack.push(17);

	std::cout << "Top element: " << mstack.top() << std::endl;

	std::cout << "Popping the top element." << std::endl;
	mstack.pop();

	std::cout << "Current stack size: " << mstack.size() << std::endl;

	std::cout << "Pushing 3, 5, 737, 0 onto the stack." << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::cout << "Iterating over the stack elements:" << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << "Copying MutantStack into a standard stack." << std::endl;
	std::stack<int> s(mstack);

	return 0;
}

