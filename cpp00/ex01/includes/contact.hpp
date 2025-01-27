#ifndef CONTACT_HPP
# define CONTACT_HPP
#include <iostream>

class Contact {

	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string	_phone_number;
		std::string _darkest_secret;

	public:
		Contact();
		~Contact();

		void		contact_info(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret);
		std::string	get_info(std::string info);
};

#endif