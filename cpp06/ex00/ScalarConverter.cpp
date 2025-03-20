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

char	ScalarConverter::toChar(std::string str)
{
	if (str.size() != 1)
	{
		std::cout << str << " cannot be converted to char" << std::endl;
		return '\0';
	}
	char c = static_cast<char>(str[0]);
	return (c);
}

int	ScalarConverter::toInt(std::string str)
{
	int nb = std::atoi(str.c_str());
	return nb;
}

float ScalarConverter::toFloat(std::string str)
{
	int nb = toInt(str);
	float flt = static_cast<float>(nb);
	return flt;
}

double ScalarConverter::toDouble(std::string str)
{
	int nb = toInt(str);
	double dbl = static_cast<double>(nb);
	return dbl;
}

void ScalarConverter::convert(const std::string str) {
	std::cout << toChar(str) << std::endl;
	std::cout <<toInt(str) << std::endl;
	std::cout <<toFloat(str) << std::endl;
	std::cout <<toDouble(str) << std::endl;
}