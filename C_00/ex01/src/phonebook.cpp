#include <iostream>
#include "phonebook.hpp"
#include "contact.hpp"

Phonebook::Phonebook( void ) {
	std::cout << "Phonebook instanciated" << std::endl;
	_currently_filled = 0;
	return;
}

Phonebook::~Phonebook( void ) {
	std::cout << "Phonebook destroyed" << std::endl;
	return;
}

std::string	prompt( std::string prompt )
{
	std::string	result = "";

	while (result.length() <= 0)
	{
		std::cout << prompt;
		std::cin >> result;
	}
	return (result);
}

void	Phonebook::display( int index ) const {
	std::cout << "Here is contact " << index << "'s informations :" << std::endl;
	_contactArray[index].Contact::display();
	return;
}

void	Phonebook::summarize( void ) const {
	int	current;

	if (_currently_filled == 0)

	std::cout << "Here are the available contacts :" << std::endl;
	current = 0;
	while (current < this->_currently_filled)
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

	// If more contacts are to be added :
	// long query_atol = std::atoi(query.c_str());

	return (true);
}

void	Phonebook::add( void ){
	_contactArray[_currently_filled] = Contact(
		_currently_filled,
		prompt("First Name: "),
		prompt("Last Name: "),
		prompt("Nickname: "),
		prompt("Phonenumber: "),
		prompt("Darkest secret: ")
	);
	_currently_filled++;
	if (_currently_filled == 8)
		_currently_filled = 0;
	return;
}

void	Phonebook::search( void ) const {

	std::string	query;

	while (1)
	{
		Phonebook::summarize();
		query = prompt("Please input the index of the contact to be displayed.\n");
		if (Phonebook::is_valid_search_query(query))
			break;
	}




	return;
}


