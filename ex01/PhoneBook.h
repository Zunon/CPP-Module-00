//
// Created by Khalifa Almheiri on 2/4/23.
//

#ifndef CPP_MODULE_00_PHONEBOOK_H
# define CPP_MODULE_00_PHONEBOOK_H
# include "Contact.h"
# ifndef PHONEBOOK_CAPACITY
#  define PHONEBOOK_CAPACITY 8
# endif

class PhoneBook {
	Contact				*oldest;
	unsigned char		size;
	Contact				contacts[PHONEBOOK_CAPACITY];
	public:
		PhoneBook (void);
		PhoneBook (const PhoneBook &);
		PhoneBook		&operator= (const PhoneBook &);
		void			addContact (const Contact &);
		Contact			*getContacts (void);
		unsigned char	getSize (void);
		~PhoneBook (void);
};

#endif //CPP_MODULE_00_PHONEBOOK_H
