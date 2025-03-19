#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try
    {
        Bureaucrat b1("Alice", 5);
        Form f1("Top Secret", 10, 50);

        std::cout << f1 << std::endl;
        b1.signForm(f1);
        std::cout << f1 << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;

    try
    {
        Bureaucrat b2("Bob", 50);
        Form f2("Confidential Report", 30, 50);

        std::cout << f2 << std::endl;
        b2.signForm(f2);
        std::cout << f2 << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;

    try
    {
        Form f3("Invalid Form", 151, 50);
    } 
    catch (const std::exception &e)
    {
        std::cerr << "Form couldn't be created: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    try
    {
        Bureaucrat b3("Charlie", 1);
        Form f4("VIP Access", 5, 10);

        b3.signForm(f4);
        b3.signForm(f4);
    } 
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}