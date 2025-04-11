#include <iostream>
#include "contact.hpp"

Contact::Contact( void ) {
	std::cout << "Contact created" << std::endl;
	return;
}

Contact::~Contact( void ) {
	std::cout << "Contact destroyed" << std::endl;
	return;
}

std::string Contact::Prompt( std::string prompt) {

	std::string	result = "";

	while (result.length() <= 0)
	{
		std::cout << prompt;
		std::cin >> result;
	}
	return (result);
}

void Contact::Fill( void ){
	std::cout << "-- Adding new contact --" << std::endl;
	this->firstName = Contact::Prompt("First Name : ");
	this->lastName = Contact::Prompt("Last Name : ");
	this->nickName = Contact::Prompt("Nickname : ");
	this->phonenumber = Contact::Prompt("Phone Number : ");
	this->darkestSecret = Contact::Prompt("Darkest Secret : ");
	std::cout << "-- Filled new contact --" << std::endl;
	return;
}
