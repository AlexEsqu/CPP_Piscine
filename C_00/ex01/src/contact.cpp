#include <iostream>
#include <iomanip>
#include "contact.hpp"

// Default constructor for phonebook initialization
Contact::Contact( void ) {
	// std::cout << "Generic Contact created" << std::endl;
}

// Using list initialisation cuz Thor from the intra videos said to
Contact::Contact(int index,
	std::string firstName,
	std::string lastName,
	std::string nickName,
	std::string phonenumber,
	std::string darkestSecret)
	: _index(index), _firstName(firstName), _lastName(lastName), _nickName(nickName),
		_phonenumber(phonenumber), _darkestSecret(darkestSecret)
{
	std::cout << "Contact #" << _index << " " << _lastName << " created" << std::endl;
}

// Default destructor
Contact::~Contact( void ) {
	// std::cout << "Contact destroyed" << std::endl;
}

std::string	Contact::resized_and_dotted( std::string string, int size ) const
{
	if ((int)string.length() > size)
	{
		string.resize(size - 1);
		string.append(".");
	}
	return (string);
}

void Contact::display( void ) const {
	std::cout << "Here are contact #" << _index << "'s informations" << std::endl;
	std::cout << "Index: " << _index << std::endl
		<< "First Name: " << _firstName << std::endl
		<< "Last Name: " << _lastName << std::endl
		<< "Nickname: " << _nickName << std::endl
		<< "Phone Number: " << _phonenumber << std::endl
		<< "Darkest Secret: " << _darkestSecret << std::endl;
}

void Contact::summarize ( void ) const {
	std::cout << "|";
	std::cout << std::setw(10);
	std::cout << _index << "|";
	std::cout << std::setw(10);
	std::cout << resized_and_dotted(_firstName, 10) << "|";
	std::cout << std::setw(10);
	std::cout << resized_and_dotted(_lastName, 10) << "|";
	std::cout << std::setw(10);
	std::cout << resized_and_dotted(_nickName, 10);
	std::cout << "|" << std::endl;
}
