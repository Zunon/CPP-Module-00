//
// Created by Khalifa Almheiri on 2/4/23.
//
#include <iostream>
#include <iomanip>
#include "PhoneBook.h"

const std::string	&MAIN_PROMPT
		= "Please enter your command: [ADD/SEARCH/EXIT]";

static std::string	trim(std::string &str)
{
	size_t first = str.find_first_not_of(' ');
	size_t last = str.find_last_not_of(' ');
	return (str.substr(first, (last-first+1)));
}

static std::string	prompt(const std::string &prompt) {
	std::string result;

	std::cout << prompt << std::endl;
	getline(std::cin, result);
	for (size_t i = 0; i < result.length(); i++)
		result[i] = toupper(result[i]);
	return (trim(result));
}

static void search_contact(PhoneBook book) {
	int	index;

	for (unsigned int i = 0; i < book.getSize(); i++) {
		std::cout << std::right << std::setw(10) << i + 1 << '|';
		std::cout << book.getContacts()[i] << std::endl;
	}
	if (book.getSize() == 0) return;
	index = std::atoi(prompt("Choose a contact ID Number").c_str()) - 1;
	if (index < 0 || index >= book.getSize())
		std::cout << "INVALID ID NUMBER" << std::endl;
	else {
		std::cout << "First Name: " << book.getContacts()[index].getFirstName() << std::endl;
		std::cout << "Last Name: " << book.getContacts()[index].getLastName() << std::endl;
		std::cout << "Nickname: " << book.getContacts()[index].getNickName() << std::endl;
	}
}

static void	add_contact(PhoneBook book) {
	std::string	first_name, last_name, nickname;

	first_name = prompt("First Name:");
	last_name = prompt("Last Name:");
	nickname = prompt("Nickname:");
	book.addContact(Contact(first_name, last_name, nickname));
}

static void	operate_on(PhoneBook book, std::string input) {
	if (input == "ADD")
		add_contact(book);
	else if (input == "SEARCH")
		search_contact(book);
}

int	main(void) {
	PhoneBook book;
	std::string input;

	book = PhoneBook();
	input = prompt(MAIN_PROMPT);
	while (input != "EXIT") {
		operate_on(book, input);
		input = prompt(MAIN_PROMPT);
	}
	return (EXIT_SUCCESS);
}
