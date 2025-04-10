#include "BitcoinExchange.hpp"

int main(int ac, char** av) {
    if (ac != 2) {
        std::cerr << "Format: ./bitcoin [filename]" << std::endl;
        return 1;
    }
    std::ifstream file(av[1]);
    if (!file.is_open()) {
        std::cerr << "Unable to open file" << std::endl;
        return 1;
    }
    std::ifstream dataBase("data.csv");
    if (!dataBase.is_open()) {
        std::cerr << "Unable to open database" << std::endl;
        return 1;
    }

    BitcoinExchange(file, dataBase);

    file.close();
    return 0;
}