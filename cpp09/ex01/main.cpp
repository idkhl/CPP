#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage example: ./RPN \"1 2 + 3 - 4 * 5 /\" " << std::endl;
		return 1;
	}
	std::string str = av[1];
	if (str.find_first_not_of("0123456789 +-*/") != std::string::npos)
	{
		std::cerr << "Error: Invalid input" << std::endl;
		return 1;
	}
	std::string s;
	std::stringstream ss(str);

	std::stack<int> stack;
	while(getline(ss, s, ' '))
	{
		// std::cout << std::endl;
		// std::cout << s << std::endl;
		if (s >= "0" && s <= "9")
		{
			// std::cout << "~~PUSH~~" << std::endl;
			stack.push(s[0] - 48);
			// std::cout << "top: " << stack.top() << std::endl;
		}
		else
		{
			// std::cout << "~~OPERATION~~" << std::endl;
			// std::cout << "operator: " << s << std::endl;
			if (stack.size() < 2)
			{
				std::cerr << "Error: Not enough numbers for operation" << std::endl;
				return 1;
			}
			int b = stack.top();
			stack.pop();
			int a = stack.top();
			stack.pop();
			if (s == "+")
				stack.push(a + b);
			else if (s == "-")
				stack.push(a - b);
			else if (s == "*")
				stack.push(a * b);
			else if (s == "/")
			{
				if (b == 0)
				{
					std::cerr << "Error: Division by zero" << std::endl;
					return 1;
				}
				stack.push(a / b);
			}
			// std::cout << "top: " << stack.top() << std::endl;
		}
	}
	int result = stack.top();
	std::cout << result << std::endl;
	return 0;
}