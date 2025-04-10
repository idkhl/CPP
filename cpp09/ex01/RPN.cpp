#include "RPN.hpp"

double RPN::calc(const std::string& str)
{
    std::string s;
    std::stringstream ss(str);

    std::stack<double> stack;
    while (getline(ss, s, ' '))
    {
        if (s.empty())
            continue;

        if (s >= "0" && s <= "9")
        {
            if (std::strtod(s.c_str(), NULL) > 10)
                throw std::invalid_argument("Error: Number is bigger than 10");
            stack.push(std::strtod(s.c_str(), NULL));
        }
        else if (s == "+" || s == "-" || s == "*" || s == "/")
        {
            if (stack.size() < 2)
                throw std::logic_error("Error: Not enough numbers for operation");

            double b = stack.top();
            stack.pop();
            double a = stack.top();
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
                    throw std::invalid_argument("Error: Division by zero");
                stack.push(a / b);
            }
        }
        else
        {
            throw std::invalid_argument("Error: Invalid character in expression");
        }
    }

    if (stack.size() != 1)
        throw std::logic_error("Error: Invalid RPN expression");

    return stack.top();
}
