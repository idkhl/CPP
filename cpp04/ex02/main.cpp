#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
// #include "WrongAnimal.hpp"
// #include "WrongCat.hpp"

int main()
{
	// Animal test;
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	std::cout << std::endl;

	std::cout << "This is a " << dog->getType() << std::endl;
	dog->makeSound();
	std::cout << "This is a " << cat->getType() << std::endl;
	cat->makeSound();
	
	std::cout << std::endl;
	delete dog;
	delete cat;
	return 0;
}