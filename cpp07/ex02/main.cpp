#include "Array.tpp"
#include <iostream>

int main() {
    try {
        std::cout << "===== Default Constructor Test =====" << std::endl;
        Array<int> emptyArray;
        std::cout << "Size of empty array: " << emptyArray.size() << std::endl;

        std::cout << "\n===== Parameterized Constructor Test =====" << std::endl;
        Array<int> intArray(5);
        std::cout << "Size of intArray: " << intArray.size() << std::endl;

        std::cout << "\n===== Assigning Values & Access Test =====" << std::endl;
        for (unsigned int i = 0; i < intArray.size(); i++) {
            intArray[i] = (i + 1) * 10; // Assign values
        }
        for (unsigned int i = 0; i < intArray.size(); i++) {
            std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
        }

        std::cout << "\n===== Copy Constructor Test =====" << std::endl;
        Array<int> copyArray(intArray);
        std::cout << "Copying intArray into copyArray..." << std::endl;
        for (unsigned int i = 0; i < copyArray.size(); i++) {
            std::cout << "copyArray[" << i << "] = " << copyArray[i] << std::endl;
        }

        std::cout << "\n===== Assignment Operator Test =====" << std::endl;
        Array<int> assignedArray;
        assignedArray = intArray;
        std::cout << "Assigning intArray to assignedArray..." << std::endl;
        for (unsigned int i = 0; i < assignedArray.size(); i++) {
            std::cout << "assignedArray[" << i << "] = " << assignedArray[i] << std::endl;
        }

        std::cout << "\n===== Out-of-Bounds Access Test =====" << std::endl;
        std::cout << intArray[10] << std::endl; // This should throw an exception

    } catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
