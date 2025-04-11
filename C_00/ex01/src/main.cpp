#include <iostream>
#include <string>
#include <cctype>
#include "contact.hpp"
#include "phonebook.hpp"

int main(void)
{
	Phonebook	myPhonebook;
	std::string	prompt;

	while (1)
	{
		std::cout << "> ";
		std::cin >> prompt;
		if (prompt.compare("EXIT") == 0)
			return (0);
		else if (prompt.compare("ADD") == 0)
			myPhonebook.Add();
		else if (prompt.compare("SEARCH") == 0)
			myPhonebook.Search();
		else
			std::cout << "Please enter command ADD, SEARCH, or EXIT.\n";
	}
	return (1);
}
