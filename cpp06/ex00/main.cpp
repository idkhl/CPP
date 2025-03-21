#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	// float a = 't';
	// std::cout << a << std::endl;
	// .0   pas essaayer pas nb
	if (argc != 2)
		return 1;
	ScalarConverter::convert(argv[1]);
	return 0;
}