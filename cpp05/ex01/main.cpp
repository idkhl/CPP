#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try
    {
        std::cout << "===== Test 1: Bureaucrat peut signer =====" << std::endl;
        Bureaucrat b1("Alice", 5);
        Form f1("Top Secret", 10, 50);

        // std::cout << "1" << std::endl;
        std::cout << f1 << std::endl;
        b1.signForm(f1);
        std::cout << f1 << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    try
    {
        std::cout << "===== Test 2: Bureaucrat ne peut PAS signer =====" << std::endl;
        Bureaucrat b2("Bob", 50);
        Form f2("Confidential Report", 30, 50);

        std::cout << f2 << std::endl;
        b2.signForm(f2);
        std::cout << f2 << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    try
    {
        std::cout << "===== Test 3: Form invalide =====" << std::endl;
        Form f3("Invalid Form", 151, 50);
    } 
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    try
    {
        std::cout << "===== Test 4: Déjà signé =====" << std::endl;
        Bureaucrat b3("Charlie", 1);
        Form f4("VIP Access", 5, 10);

        b3.signForm(f4);
        b3.signForm(f4);
    } 
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}