#include "Data.hpp"

Data::Data(): _data(0), _name("dflt") {}

Data::Data(const std::string &name, const int &data): _data(data), _name(name) {}

Data::Data(const Data &copy): _data(copy._data), _name(copy._name) {}

Data::~Data() {}

int Data::getData() {
	return _data;
}

std::string Data::getName() {
	return _name;
}