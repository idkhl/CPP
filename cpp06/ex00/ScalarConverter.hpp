#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>

class ScalarConverter
{
	private:

	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		ScalarConverter &operator=(const ScalarConverter &copy);
		~ScalarConverter();
	
	static void convert(const std::string str);

};

#endif