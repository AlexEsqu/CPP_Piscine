#include <iostream>
#include <string>
#include <cctype>
#include "contact.hpp"
#include "phonebook.hpp"
#include "prompt.hpp"

int main(void)
{
	Phonebook		myPhonebook;
	std::string	cmd;

	while (1)
	{
		cmd = prompt("Please enter command ADD, SEARCH, or EXIT.\n", ALPHA);
		if (cmd.compare("ADD") == 0)
			myPhonebook.add();
		else if (cmd.compare("SEARCH") == 0)
			myPhonebook.search();
		else if (cmd.compare("EXIT") == 0)
			return (0);
	}
	return (1);
}
