#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
#include "contact.hpp"

class PhoneBook {

	private:
		Contact _list[8];
		int		_index;
		int		_nb_contacts;


	public:
		PhoneBook();
		~PhoneBook();

	void	add_contact(void);
	void	search(void);
};

#endif