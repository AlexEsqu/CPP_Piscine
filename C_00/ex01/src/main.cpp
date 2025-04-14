#include <iostream>
#include <string>
#include <cctype>
#include "contact.hpp"
#include "phonebook.hpp"
#include "prompt.hpp"

int main(void)
{
	Phonebook	myPhonebook;
	std::string	cmd;

	while (1)
	{
		std::cout << "Please enter command ADD, SEARCH, or EXIT." << std::endl;
		std::cout << "> ";
		std::getline(std::cin, cmd);
		if (std::cin.bad() || std::cin.eof() || std::cin.fail())
			return (1);
		if (cmd.empty())
			continue;
		else if (cmd.compare("ADD") == 0)
			myPhonebook.add();
		else if (cmd.compare("SEARCH") == 0)
			myPhonebook.search();
		else if (cmd.compare("EXIT") == 0)
			return (0);
	}
	return (1);
}
