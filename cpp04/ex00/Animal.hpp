#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

class Animal
{
	protected:
		std::string _type;

	public:
		Animal();
		Animal(const Animal &other);
		Animal &operator=(const Animal &other);
		~Animal();

		std::strinm getType();
		void makeSound();
};

class Dog : public Animal
{
	private:


	public:
		Dog();
		Dog(const Dog &other);
		Dog &operator=(const Dog &other);
		~Dog();
};

class Cat : public Animal
{
	private:

	
	public:
		Cat();
		Cat(const Cat &other);
		Cat &operator=(const Cat &other);
		~Cat();
};

std::ostream &operator<<(std::ostream &out, const Animal &type);

#endif