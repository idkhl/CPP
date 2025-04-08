#include "iter.hpp"

template <typename T>
void	print(const T& c)
{
	std::cout << c ;
}

int	main(void)
{
	std::string tab1[] = {
		"hello ",
		"world"
	};
	iter(tab1, 2, print<std::string>);
	std::cout << std::endl;

	int tab2[] = {1, 2, 3, 4};
	iter(tab2, 4, print<int>);
	std::cout << std::endl;
	
	char tab3[] = "test\n";
	iter(tab3, 5, print<char>);
	return 0;
}