#include "BitcoinExchange.hpp"

int parseFile(const std::string& date, const std::string& value) {
    std::string trimmedDate = trim(date);
    std::string trimmedValue = trim(value);

    if (trimmedDate.empty() || trimmedValue.empty()) {
        std::cerr << "Error: Missing date or value." << std::endl;
        return 1;
    }
    if (!isValidDate(trimmedDate)) {
        std::cerr << "Error: Invalid date format => " << trimmedDate << std::endl;
        return 1;
    }
    if (!isValidValue(trimmedValue)) {
        std::cerr << "Error: Invalid value => " << trimmedValue << std::endl;
        return 1;
    }
    return 0;
}

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

    std::map<std::string, double> bitcoin;
    std::string dataLine;
    while (std::getline(dataBase, dataLine)) {
        std::string dataDate = trim(dataLine.substr(0, dataLine.find(",")));
        std::string dataRate = trim(dataLine.substr(dataLine.find(",") + 1));
        bitcoin[dataDate] = std::strtod(dataRate.c_str(), NULL);
    }
    dataBase.close();

    std::map<std::string, double> input;
    std::string inputLine;
    while (std::getline(file, inputLine)) {
        std::string inputDate = trim(inputLine.substr(0, inputLine.find("|")));
        std::string inputValue = (inputLine.find("|") == std::string::npos) ? "" : trim(inputLine.substr(inputLine.find("|") + 1));

        if (parseFile(inputDate, inputValue) == 1) {
            continue;
        }

        std::map<std::string, double>::iterator it = bitcoin.find(inputDate);
        if (it == bitcoin.end()) {
            it = bitcoin.lower_bound(inputDate);
            if (it == bitcoin.begin() && it->first > inputDate) {
                std::cerr << "Error: No valid lower date found for " << inputDate << std::endl;
                continue;
            }
            if (it == bitcoin.end() || it->first > inputDate) {
                --it;
            }
        }

        std::cout << inputDate << " => " << inputValue << " = " << it->second * std::strtod(inputValue.c_str(), NULL) << std::endl;
    }
    file.close();
    return 0;
}