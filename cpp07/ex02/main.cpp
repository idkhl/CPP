#include "Array.tpp"

int	main(void)
{
	Array<int> arr(2);
	Array<int> copy = arr;
	try
	{
		copy[1] = 10;
		std::cout << "copy = " << copy[1] << std::endl;
		std::cout << "arr = " << arr[1] << std::endl;
		std::cout << "size = " << arr.size() << std::endl;
		std::cout << arr[3] << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	Array<int> emptyArray;
    std::cout << "Empty array size = " << emptyArray.size() << std::endl;

	return 0;
}