#include <iostream>
#include <iomanip>
#include <sstream>
#include "contact.hpp"
#include "phonebook.hpp"

PhoneBook::PhoneBook(void) {
	this->_index = 0;
	this->_nb_contacts = 0;
	std::cout << "Phonebook constructor called" << std::endl;
	return;
}

PhoneBook::~PhoneBook(void) {
	std::cout << "Phonebook destructor called" << std::endl;
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
		if (std::cin.eof())
		{
			std::cout << "BYE" << std::endl;
			return ;
		}
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
		if (std::cin.eof())
		{
			std::cout << "BYE" << std::endl;
			return ;
		}
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
		if (std::cin.eof())
		{
			std::cout << "BYE" << std::endl;
			return ;
		}
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
		if (std::cin.eof())
		{
			std::cout << "BYE" << std::endl;
			return ;
		}
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
		if (std::cin.eof())
		{
			std::cout << "BYE" << std::endl;
			return ;
		}
		if (darkest_secret.empty())
		{
			std::cout << "Please don't leave field empty" << std::endl;
			continue;
		}
		break;
	}

	this->_list[this->_index].contact_info(first_name, last_name, nickname, phone_number, darkest_secret);
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

std::string	Contact::get_info(std::string info)
{
	std::string	tmp;

	if (info == "first_name")
		return (this->_first_name);
	if (info == "last_name")
		return (this->_last_name);
	if (info == "nickname")
		return (this->_nickname);
	if (info == "phone_number")
		return (this->_phone_number);
	if (info == "darkest_secret")
		return (this->_darkest_secret);
	return NULL;
}

void	PhoneBook::search()
{
	std::string input;

	if (_nb_contacts == 0)
	{
		std::cout << "No contacts to display, please add one" << std::endl;
		return;
	}
	std::cout	<< std::setw(10) << "INDEX" << "|" 
				<< std::setw(10) << "FIRST NAME" << "|" 
				<< std::setw(10) << "LAST NAME" << "|" 
				<< std::setw(10) << "NICK NAME" << "|" 
				<< std::endl;
	for (int i = 0; i < this->_nb_contacts; i++)
	{
		std::string first_name = this->_list[i].get_info("first_name");
		std::string last_name = this->_list[i].get_info("last_name");
		std::string nickname = this->_list[i].get_info("nickname");

		if (first_name.length() > 10)
		{
			first_name.resize(9);
			first_name += ".";
		}
		if (last_name.length() > 10)
		{
			last_name.resize(9);
			last_name += ".";
		}
		if (nickname.length() > 10)
		{
			nickname.resize(9);
			nickname += ".";
		}
		std::cout	<< std::setw(10) << i << "|" 
					<< std::setw(10) << first_name << "|" 
					<< std::setw(10) << last_name << "|" 
					<< std::setw(10) << nickname << "|" << std::endl;
	}
	std::cout << "ENTER INDEX TO GET MORE INFO" << std::endl;
	int index;
	while (1)
	{
		std::getline(std::cin, input);
		std::stringstream ss(input);
		if (!(ss >> index))
		{
			std::cout << "Invalid input. Please enter a valid number." << std::endl;
			continue;
		}
		if (index < 0 || index >= _nb_contacts)
		{
			std::cout << "Index out of range. Please enter a number up to " << _nb_contacts - 1 << "." << std::endl;
			continue;
		}
		break;
	}
	std::cout << "First Name: " << this->_list[index].get_info("first_name") << std::endl;
	std::cout << "Last Name: " << this->_list[index].get_info("last_name") << std::endl;
	std::cout << "Nickname: " << this->_list[index].get_info("nickname") << std::endl;
	std::cout << "Phone Number: " << this->_list[index].get_info("phone_number") << std::endl;
	std::cout << "Darkest Secret: " << this->_list[index].get_info("darkest_secret") << std::endl;
}

int	main()
{
	PhoneBook	phonebook;
	std::string input;

	while (1)
	{
		std::cout << "ENTER A COMMAND" << std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << "BYE" << std::endl;
			return 0;
		}
		if (input.compare("ADD") == 0)
			phonebook.add_contact();
		else if (input.compare("SEARCH") == 0)
			phonebook.search();
		else if (input.compare("EXIT") == 0)
			break;
		else
			std::cout << "Not a valid command" << std::endl;
	}
	return 0;
}