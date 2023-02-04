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

static std::string	truncate_to_10(std::string name) {
	if (name.length() > 10)
		return (name.substr(0, 9) + '.');
	return (name);
}

std::ostream 	&operator<<(std::ostream &stream, const Contact &contact) {
	stream << std::right << std::setw(10) <<  truncate_to_10(contact.getFirstName());
	stream << '|';
	stream << std::right << std::setw(10) << truncate_to_10(contact.getLastName());
	stream << '|';
	stream << std::right << std::setw(10) << truncate_to_10(contact.getNickName());
	return (stream);
}

std::string	Contact::getFirstName(void) const {
	return (this->firstName);
}

std::string	Contact::getLastName(void) const {
	return (this->lastName);
}

std::string	Contact::getNickName(void) const {
	return (this->nickName);
}

Contact::~Contact(void) {
}
