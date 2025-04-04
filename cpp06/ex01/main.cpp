#include "Data.hpp"
#include "Serializer.hpp"

int main()
{
	std::string name = "TestName";
	int dataValue = 42;
	Data originalData(name, dataValue);
	uintptr_t raw = Serializer::serialize(&originalData);
	std::cout << "Serialized value: " << raw << std::endl;
	Data* deserializedData = Serializer::deserialize(raw);
	std::cout << "Original Data address: " << &originalData << std::endl;
	std::cout << "Deserialized Data address: " << deserializedData << std::endl;
	std::cout << "Original Data name: " << originalData.getName() << ", data: " << originalData.getData() << std::endl;
	std::cout << "Deserialized Data name: " << deserializedData->getName() << ", data: " << deserializedData->getData() << std::endl;

	return 0;
}
