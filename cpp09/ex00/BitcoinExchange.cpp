#include "BitcoinExchange.hpp"

bool isValidDate(const std::string& date) {
    struct tm tm;
    return strptime(date.c_str(), "%Y-%m-%d", &tm) != NULL;
}

bool isValidValue(const std::string& value) {
    char* end;
    double val = std::strtod(value.c_str(), &end);
    if (*end != '\0' || val < 0 || val > 1000) {
        return false;
    }
    return true;
}

std::string trim(const std::string& str) {
    size_t start = str.find_first_not_of(" \t");
    size_t end = str.find_last_not_of(" \t");
    return (start == std::string::npos || end == std::string::npos) ? "" : str.substr(start, end - start + 1);
}

int parseFile(const std::string& date, const std::string& value) {
    std::string trimmedDate = trim(date);
    std::string trimmedValue = trim(value);

    if (trimmedDate == "date" || trimmedValue == "value")
        return 1;

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

void BitcoinExchange(std::ifstream &file, std::ifstream &dataBase)
{
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
}