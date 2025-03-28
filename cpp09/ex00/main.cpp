#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Format: ./bitcoin [filename]" << std::endl;
		return 1;
	}
	std::ifstream file(av[1]);
	if (!file.is_open())
	{
		std::cerr << "Unable to open file" << std::endl;
		return 1;
	}
	std::ifstream dataBase("data.csv");
	if(!dataBase.is_open())
	{
		std::cerr << "Unable to open database" << std::endl;
		return 1;
	}
	std::map<std::string, double> bitcoin;
	std::string dataLine;
	while (std::getline(dataBase, dataLine))
	{
		std::string date = dataLine.substr(0, dataLine.find(","));
		std::string rate = dataLine.substr(dataLine.find(",") + 1);
		// std::cout << rate << std::endl;
		bitcoin[date] = std::atof(rate.c_str());
	}
	dataBase.close();
	// std::cout << "Bitcoin exchange rate on 2021-10-30: " << bitcoin["2021-10-30"] << std::endl;
	std::map<std::string, double> input;
	std::string inputLine;
	while (std::getline(file, inputLine))
	{

	}
	return 0;
}