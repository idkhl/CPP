#include <iostream>
#include <fstream>

void	replace(char **av)
{
	std::ifstream file(av[1]);
	if (!file.is_open())
	{
		std::cerr << "Unable to open file" << std::endl;
		return;
	}
	std::string tmp = ".replace";
	std::string filename = av[1] + tmp;
	std::ofstream temp(filename.c_str());
	if (!temp.is_open())
	{
		std::cerr << "Unable to create temp file" << std::endl;
		file.close();
		return;
	}

	std::string s1 = av[2];
	std::string s2 = av[3];
	if (s1.empty())
	{
		std::cerr << "Error: s1 cannot be an empty string" << std::endl;
		file.close();
		temp.close();
		std::remove(filename.c_str());
		return;
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
}

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Wrong format [./sed <filename> s1 s2]" << std::endl;
		return -1;
	}
	replace(av);

	return 0;
}