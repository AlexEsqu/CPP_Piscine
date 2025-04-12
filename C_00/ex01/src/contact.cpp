#include <iostream>
#include "contact.hpp"

// Default constructor
Contact::Contact( void ) {

}

// Using list initialisation cuz Thor said to
Contact::Contact(int index,
	std::string firstName,
	std::string lastName,
	std::string nickName,
	std::string phonenumber,
	std::string darkestSecret)
	: _index(index), _darkestSecret(darkestSecret), _phonenumber(phonenumber),
	_nickName(nickName), _lastName(lastName), _firstName(firstName) {
	std::cout << "Contact #" << this->_index << " " << this->_lastName << "created" << std::endl;
}

Contact::~Contact( void ) {
	std::cout << "Contact destroyed" << std::endl;
	return;
}

void Contact::display( void ) const {
	std::cout << "Index: " << this->_index << "\n"
		<< "First Name: " << this->_firstName << "\n"
		<< "Last Name: " << this->_lastName << "\n"
		<< "Nickname: " << this->_nickName << "\n"
		<< "Phone Number: " << this->_phonenumber << "\n"
		<< "Darkest Secret: " << this->_darkestSecret;
}

void Contact::summarize ( void ) const {
	std::cout << "Index: " << this->_index << "\n"
		<< "First Name: " << this->_firstName << "\n"
		<< "Last Name: " << this->_lastName << "\n"
		<< "Nickname: " << this->_nickName << "\n";
}
