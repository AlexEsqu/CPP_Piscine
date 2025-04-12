#include <iostream>
#include <string>
#include <cctype>
#include "contact.hpp"
#include "phonebook.hpp"

int main(void)
{
	Phonebook	myPhonebook;
	std::string	cmd;

	while (1)
	{
		std::cout << "> ";
		std::getline (std::cin, cmd);
		if (cmd.compare("EXIT") == 0)
			return (0);
		else if (cmd.compare("ADD") == 0)
			myPhonebook.add();
		else if (cmd.compare("SEARCH") == 0)
			myPhonebook.search();
		else
			std::cout << "Please enter command ADD, SEARCH, or EXIT.\n";
	}
	return (1);
}
