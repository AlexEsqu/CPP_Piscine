#include "prompt.hpp"

// Protecting cin in case of signals or reading errors
std::string	prompt( std::string prompt )
{
	std::string	result;

	while (result.empty() && !(std::cin.eof()))
	{
		std::cout << prompt;
		std::cout << "> ";
		std::getline(std::cin, result);
		if (std::cin.bad() || std::cin.eof() || std::cin.fail())
		{
			std::cout << "Encontered an error, exiting..." << std::endl;
			exit(1);
		}
		if (result.empty())
			continue;
	}
	return (result);
}


