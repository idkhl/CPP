#include "RPN.hpp"

double RPN::evaluate(const std::string& expression) {
    std::stack<double> stack;
    std::stringstream ss(expression);
    std::string token;

    while (getline(ss, token, ' ')) {
        if (token >= "0" && token <= "9") {
            stack.push(std::strtod(token.c_str(), NULL));
        } else {
            if (stack.size() < 2) {
                throw std::invalid_argument("Error: Not enough numbers for operation");
            }
            double b = stack.top();
            stack.pop();
            double a = stack.top();
            stack.pop();
            if (token == "+")
                stack.push(a + b);
            else if (token == "-")
                stack.push(a - b);
            else if (token == "*")
                stack.push(a * b);
            else if (token == "/") {
                if (b == 0) {
                    throw std::invalid_argument("Error: Division by zero");
                }
                stack.push(a / b);
            } else {
                throw std::invalid_argument("Error: Invalid operator");
            }
        }
    }

    if (stack.size() != 1) {
        throw std::invalid_argument("Error: Invalid expression");
    }

    return stack.top();
}
