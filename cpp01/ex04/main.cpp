#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Wrong format [./sed <filename> s1 s2]" << std::endl;
		return -1;
	}
	std::ifstream file(av[1]);
	if (!file.is_open())
	{
		std::cerr << "Unable to open file" << std::endl;
		return -1;
	}
	std::ofstream temp("temp.txt");
	if (!temp.is_open())
	{
		std::cerr << "Unable to create temp file" << std::endl;
		file.close();
		return -1;
	}

	std::string s1 = av[2];
	std::string s2 = av[3];
	if (s1.empty())
	{
		std::cerr << "Error: s1 cannot be an empty string" << std::endl;
		file.close();
		temp.close();
		std::remove("temp.txt");
		return -1;
	}

	std::string line;
	while (getline(file, line))
	{
		size_t index = 0;
		while ((index = line.find(s1, index)) != std::string::npos)
		{
			line = line.substr(0, index) + s2 + line.substr(index + s1.length());
			index += s2.length();
		}
		temp << line << std::endl;
	}

	file.close();
	temp.close();
	if (std::remove(av[1]) != 0)
	{
		std::cerr << "Error deleting original file" << std::endl;
		return -1;
	}
	if (std::rename("temp.txt", av[1]) != 0)
	{
		std::cerr << "Error renaming temp file" << std::endl;
		return -1;
	}

	return 0;
}