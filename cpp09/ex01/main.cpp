#include "RPN.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
        std::cerr << "Usage example: ./RPN \"1 2 + 3 - 4 * 5 /\"" << std::endl;
        return 1;
    }

    try {
        double result = RPN::evaluate(av[1]);
        std::cout << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}