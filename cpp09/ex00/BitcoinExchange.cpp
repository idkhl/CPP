#include "BitcoinExchange.hpp"

// Ensure these functions are only defined here.
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
