//
// Created by Khalifa Almheiri on 2/4/23.
//

#include "PhoneBook.h"

PhoneBook::PhoneBook(void) {
	oldest = NULL;
	size = 0;
}

PhoneBook::PhoneBook(const PhoneBook &book) {
	for (int i = 0; i < book.size; i++)
		contacts[i] = book.contacts[i];
	oldest = contacts + (book.oldest - book.contacts);
	size = book.size;
}

PhoneBook	&PhoneBook::operator=(const PhoneBook &book) {
	if (this != &book) {
		for (int i = 0; i < 8; i++)
			contacts[i] = book.contacts[i];
		oldest = contacts + (book.oldest - book.contacts);
		size = book.size;
	}
	return (*this);
}

void		PhoneBook::addContact(const Contact &contact) {
	if (size == 0)
		oldest = contacts;
	if (size == PHONEBOOK_CAPACITY) {
		*oldest = contact;
		oldest = contacts + ((oldest - contacts + 1) % PHONEBOOK_CAPACITY);
	}
	else
		contacts[size++] = contact;
}

Contact		*PhoneBook::getContacts(void) {
	return (contacts);
}

PhoneBook::~PhoneBook(void) {
	oldest = NULL;
	size = 0;
}
