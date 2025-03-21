#ifndef DATA_HPP
#define DATA_HPP

#include <string>

class Data {
private:
	int _data;
	std::string _name;

public:
	Data();
	Data(const std::string &name, const int &data);
	Data(const Data &copy);
	~Data();

	int getData();
	std::string getName();
};

#endif