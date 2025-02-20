#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
// #include "WrongAnimal.hpp"
// #include "WrongCat.hpp"

int main()
{
	// const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	// const WrongAnimal* wrongCatAnimal = new WrongAnimal();
	// const WrongCat* wrongCat = new WrongCat();
	std::cout << std::endl;

	// std::cout << "This is an " << meta->getType() << std::endl;
	// meta->makeSound();
	std::cout << "This is a " << dog->getType() << std::endl;
	dog->makeSound();
	std::cout << "This is a " << cat->getType() << std::endl;
	cat->makeSound();
	// std::cout << "This is a " << wrongCatAnimal->getType() << std::endl;
	// wrongCatAnimal->makeSound();
	// std::cout << "This is a " << wrongCat->getType() << std::endl;
	// wrongCat->makeSound();
	
	std::cout << std::endl;
	delete dog;
	delete cat;
	// delete meta;
	// delete wrongCatAnimal;
	// delete wrongCat;
	return 0;
}