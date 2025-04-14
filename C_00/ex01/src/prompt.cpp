#include "prompt.hpp"

std::string	prompt( std::string prompt )
{
	std::string	result = "";

	while (result.empty() && !(std::cin.eof()))
	{
		std::cout << prompt;
		std::getline(std::cin, result);
		if (std::cin.bad())
			return (NULL);
		else if (std::cin.eof())
			return (NULL);
		else if (std::cin.fail())
			return (NULL);
		if (result.empty())
			continue;
	}
	return (result);
}


