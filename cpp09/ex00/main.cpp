#include "BitcoinExchange.hpp"

int	parseFile(std::string date, std::string value)
{
	struct tm tm;
	if (date == "" || value == "")
	{
		std::cerr << "Error: Bad input" << std::endl;
		return 1;
	}
	if (date == "date " || value == " value")
		return 1;
	if (value.find_first_not_of("0123456789. -") != std::string::npos)
	{
		std::cerr << "Error: Invalid value" << std::endl;
		return 1;
	}
	if (date.find_first_not_of("0123456789- ") != std::string::npos)
	{
		std::cerr << "Error: Invalid date" << std::endl;
		return 1;
	}
	if (value.find("-") != std::string::npos)
	{
		std::cerr << "Error: not a positive number" << std::endl;
		return 1;
	}
	if (std::strtod(value.c_str(), NULL) > std::numeric_limits<int>::max())
	{
		std::cerr << "Error: too large of a number" << std::endl;
		return 1;
	}
	if (!strptime(date.c_str(), "%Y-%m-%d", &tm))
	{
		std::cerr << "Error: Invalid date" << std::endl;
		return 1;
	}
	return 0;
}

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
		std::string dataDate = dataLine.substr(0, dataLine.find(","));
		std::string dataRate = dataLine.substr(dataLine.find(",") + 1);
		bitcoin[dataDate] = std::strtod(dataRate.c_str(), NULL);
	}
	dataBase.close();

	std::map<std::string, double> input;
	std::string inputLine;
	while (std::getline(file, inputLine))
	{
		std::string inputDate = inputLine.substr(0, inputLine.find("|"));
		std::string inputValue;
		if (inputLine.find("|") == std::string::npos)
			inputValue = "";
		else
			inputValue = inputLine.substr(inputLine.find("|") + 1);
		input[inputDate] = std::strtod(inputValue.c_str(), NULL);
		if (parseFile(inputDate, inputValue) == 1)
			continue;

		std::map<std::string, double>::iterator it = bitcoin.find(inputDate);
		if (it == bitcoin.end())
		{
			it = bitcoin.lower_bound(inputDate);
			if (it == bitcoin.begin() && it->first > inputDate)
			{
				std::cerr << "Error: No valid lower date found for " << inputDate << std::endl;
				continue;
			}
			if (it == bitcoin.end() || it->first > inputDate)
				--it;
		}

		std::cout << inputDate << "=>" << inputValue << " = " << it->second * input[inputDate] << std::endl;
	}
	file.close();
	return 0;
}