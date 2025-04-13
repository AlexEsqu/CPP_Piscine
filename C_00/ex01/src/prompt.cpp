#include "prompt.hpp"

std::string	prompt( std::string prompt )
{
	std::string	result = "";

	while (result.empty())
	{
		std::cout << prompt;
		std::getline(std::cin, result);
	}
	return (result);
}


