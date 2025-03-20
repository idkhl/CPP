#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>
# include <cstdlib>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		ScalarConverter &operator=(const ScalarConverter &copy);
		~ScalarConverter();

	static char	toChar(std::string str);
	static int	toInt(std::string str);
	static float toFloat(std::string str);
	static double toDouble(std::string str);

	public:
		static void convert(const std::string str);

};

#endif