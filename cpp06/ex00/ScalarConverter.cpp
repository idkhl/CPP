#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &copy) {
	(void)copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy) {
	(void)copy;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::printChar(char c)
{
    if (c < 32 || c > 126)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << c << "'" << std::endl;
}

void ScalarConverter::convert(const std::string str) {
	int intValue;
    std::istringstream iss(str);
    if (!(iss >> intValue))
	{
		std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    }
	else
	{
		printChar(static_cast<char>(intValue));
        std::cout << "int: " << intValue << std::endl;
    }
    float floatValue = std::strtof(str.c_str(), NULL);
    double doubleValue = std::strtod(str.c_str(), NULL);
    std::cout << "float: " << floatValue << "f" << std::endl;
    std::cout << "double: " << doubleValue << std::endl;
}