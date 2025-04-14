#include <iostream>
#include <cstdlib>
#include "phonebook.hpp"
#include "contact.hpp"
#include "prompt.hpp"

Phonebook::Phonebook( void ) {
	// std::cout << "Phonebook instanciated" << std::endl;
	_currently_filled = 0;
	_index_to_be_filled = 0;
	return;
}

Phonebook::~Phonebook( void ) {
	// std::cout << "Phonebook destroyed" << std::endl;
	return;
}

void	Phonebook::display( int index ) const {
	std::cout << "Here is contact " << index << "'s informations :" << std::endl;
	_contactArray[index].Contact::display();
	return;
}

void	Phonebook::summarize( void ) const {
	int	current;

	current = 0;
	std::cout << "Here are the available contacts :" << std::endl;
	while (current < std::min(_currently_filled, MAX_CONTACT))
	{
		_contactArray[current].summarize();
		current++;
	}
}

bool	Phonebook::is_valid_search_query(std::string query) const {

	if (query.empty())
	{
		std::cerr << "Empty field." << std::endl;
		return (false);
	}
	if (query.size() > 1)
	{
		std::cerr << "Invalid index." << std::endl;
		return (false);
	}
	if (query[0] < '0' || query[0] > '9')
	{
		std::cerr << "Only unsigned digits can be used as input." << std::endl;
		return (false);
	}
	if (query[0] > '7')
	{
		std::cerr << "Our super modern C++ Phonebook only contains 8 addresses." << std::endl;
		return (false);
	}
	return (true);
}

void	Phonebook::add( void ){
	std::string firstName = prompt("First Name: ");
	std::string lastName = prompt("Last Name: ");
	std::string nickName= prompt("Nickname: ");
	std::string phoneNumber = prompt("Phonenumber: ");
	std::string darkestSecret = prompt("Darkest secret: ");

	_contactArray[_index_to_be_filled] = Contact(
		_index_to_be_filled,
		firstName,
		lastName,
		nickName,
		phoneNumber,
		darkestSecret
	);
	_currently_filled++;
	_index_to_be_filled++;
	if (_index_to_be_filled == 8)
		_index_to_be_filled = 0;
}

void	Phonebook::search( void ) const {

	std::string	query;
	long		sought_index;
	char		*pEnd;

	if (_currently_filled == 0)
	{
		std::cout << "The Phonebook is currently empty." << std::endl;
		return;
	}
	while (1)
	{
		Phonebook::summarize();
		query = prompt("Please input the index of the contact to be displayed.\n");
		if (Phonebook::is_valid_search_query(query))
		{
			sought_index = std::strtol(query.c_str(), &pEnd, 10);
			if (sought_index < _currently_filled)
				_contactArray[sought_index].display();
			else
				std::cout << "Contact does not exist yet." << std::endl;
			return ;
		}
	}
}


