#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	std::cout << std::endl;

	std::cout << "There is an " << meta->getType() << std::endl;
	meta->makeSound();
	std::cout << "This is a " << dog->getType() << std::endl;
	dog->makeSound();
	std::cout << "This is a " << cat->getType() << std::endl;
	cat->makeSound();

	std::cout << std::endl;
	delete dog;
	delete cat;
	delete meta;
	return 0;
}