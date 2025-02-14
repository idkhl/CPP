#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

class Animal
{
	protected:
		std::string type;

	public:
		Animal();
		Animal(const Animal &other);
		Animal &operator=(const Animal &other);
		~Animal();
};

class Dog : public Animal
{
	private:


	public:
		Dog();
		Dog(const Dog &other);
		Dog &operator=(const Dog &other);
		~Dog();
}

#endif