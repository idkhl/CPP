#include <iostream>
#include "contact.hpp"
#include "phonebook.hpp"

PhoneBook::PhoneBook(void) {
	std::cout << "Phonebook constructor called" << std::endl;
	return;
}

PhoneBook::~PhoneBook(void) {
	std::cout << "Phonebook desstructor called" << std::endl;
	return;
}

Contact::Contact(void) {
	std::cout << "Contact constructor called" << std::endl;
	return;
}

Contact::~Contact(void) {
	std::cout << "Contact destructor called" << std::endl;
	return;
}

void	PhoneBook::add_contact()
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string	phone_number;
	std::string darkest_secret;

	while (1)
	{
		std::cout << "First name?" << std::endl;
		std::getline(std::cin, first_name);
		std::cout << "First name: " << first_name << std::endl;
	}
	while (1)
	{
		std::cout << "Last name?" << std::endl;
		std::getline(std::cin, last_name);
		std::cout << "Last name: " << last_name << std::endl;
	}
	while (1)
	{
		std::cout << "Nickname?" << std::endl;
		std::getline(std::cin, nickname);
		std::cout << "Nickname: " << nickname << std::endl;
	}
	while (1)
	{
		std::cout << "Phone number?" << std::endl;
		std::getline(std::cin, phone_number);
		std::cout << "Phone number: " << phone_number << std::endl;
	}
	while (1)
	{
		std::cout << "Darkest secret?" << std::endl;
		std::getline(std::cin, darkest_secret);
		std::cout << "Darkest secret: " << darkest_secret << std::endl;
	}
}

int	main()
{
	PhoneBook	phonebook;
	std::string input;

	while (1)
	{
		std::cout << "ENTER A COMMAND" << std::endl;
		std::getline(std::cin, input);
		if (input.compare("ADD") == 0)
			phonebook.add_contact();
		// if (input.compare("SEARCH") == 0)
		// 	phonebook.search();
		if (input.compare("EXIT") == 0)
			break;
	}
	return 0;
}