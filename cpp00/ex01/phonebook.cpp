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

int	check_number(std::string phone_number)
{
	for (size_t i = 0; i < phone_number.length(); i++)
	{
		if (std::isdigit((int)phone_number[i]) == 0)
			return -1;
	}
	return 0;
}

void	Contact::contact_info(std::string first_name, std::string last_name, 	std::string nickname, std::string phone_number, std::string darkest_secret)
{
	this->_first_name = first_name;
	this->_last_name = last_name;
	this->_nickname = nickname;
	this->_phone_number = phone_number;
	this->_darkest_secret = darkest_secret;
	return ;
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
		std::cout << "> First name?" << std::endl;
		std::getline(std::cin, first_name);
		if (first_name.empty())
		{
			std::cout << "Please don't leave field empty" << std::endl;
			continue;
		}
		break;
	}
	while (1)
	{
		std::cout << "> Last name?" << std::endl;
		std::getline(std::cin, last_name);
		if (last_name.empty())
		{
			std::cout << "Please don't leave field empty" << std::endl;
			continue;
		}
		break;
	}
	while (1)
	{
		std::cout << "> Nickname?" << std::endl;
		std::getline(std::cin, nickname);
		if (nickname.empty())
		{
			std::cout << "Please don't leave field empty" << std::endl;
			continue;
		}
		break;
	}
	while (1)
	{
		std::cout << "> Phone number?" << std::endl;
		std::getline(std::cin, phone_number);
		if (phone_number.empty() || check_number(phone_number) == -1)
		{
			std::cout << "Please put in valid number" << std::endl;
			continue;
		}
		break;
	}
	while (1)
	{
		std::cout << "> Darkest secret?" << std::endl;
		std::getline(std::cin, darkest_secret);
		if (darkest_secret.empty())
		{
			std::cout << "Please don't leave field empty" << std::endl;
			continue;
		}
		break;
	}
	this->_list[this->_index].contact_info(first_name, last_name, nickname, phone_number, darkest_secret);
	// this->_list[this->_index]._first_name = first_name;
	if (this->_index == 7)
	{
		this->_index = 0;
		this->_nb_contacts = 8;
	}
	else
	{
		this->_index++;
		if (this->_nb_contacts < 8)
			this->_nb_contacts++;
	}
}

void	PhoneBook::search(std::string input)
{
	for (_index < 8; _index++;)
	{
		if (input.compare())
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
		if (input.compare("SEARCH") == 0)
			phonebook.search(input);
		if (input.compare("EXIT") == 0)
			break;
		else
			std::cout << "Not a valid command" << std::endl;
	}
	return 0;
}