//
// Created by Khalifa Almheiri on 2/4/23.
//

#include "Contact.h"

Contact::Contact(void) {
	firstName = "John";
	lastName = "Doe";
	nickName = "Johnny Apples";
}

Contact::Contact(const Contact &contact) {
	firstName = contact.firstName;
	lastName = contact.lastName;
	nickName = contact.nickName;
}

Contact::Contact(std::string firstName, std::string lastName,
	std::string nickName) {
	this->firstName = firstName;
	this->lastName = lastName;
	this->nickName = nickName;
}

Contact		&Contact::operator= (const Contact &contact) {
	if (this != &contact) {
		firstName = contact.firstName;
		lastName = contact.lastName;
		nickName = contact.nickName;
	}
	return (*this);
}

std::string	Contact::getFirstName(void) {
	return (this->firstName);
}

std::string	Contact::getLastName(void) {
	return (this->lastName);
}

std::string	Contact::getNickName(void) {
	return (this->nickName);
}

Contact::~Contact(void) {
}
