#include "prompt.hpp"

bool	is_supported_char( int c, e_prompt_types mode ) {

	// std::cout << "Testing char [" << (char)c << "]" << std::endl;

	if (std::iscntrl(c))
	{
		std::cout << "Received an unsupported character." << std::endl;
		return (false);
	}
	if (mode == ALPHA) {
		if (std::isprint(c))
			return (true);
		std::cout << "This field only supports alphabetical characters." << std::endl;
		return (false);
	}
	if (mode == NUM) {
		if (std::isdigit(c))
			return (true);
		std::cout << "This field only supports numerical characters." << std::endl;
		return (false);
	}
	return (false);
}

bool	is_valid_intput( std::string input, e_prompt_types mode ) {

	std::string	sanitized;

	for (std::string::size_type i = 0; i < input.size(); ++i) {
		if (!is_supported_char(input[i], mode))
			return (false);
	}
	return (true);
}


// Protecting cin in case of signals or reading errors
std::string	prompt( std::string prompt, e_prompt_types mode ) {
	std::string	result;

	while (!std::cin.bad() && !std::cin.fail() && !std::cin.eof())
	{
		std::cout << prompt;
		std::cout << "> ";
		getline(std::cin, result);
		if (!is_valid_intput(result, mode))
			continue;
		if (result.empty())
			continue;
		else
			return (result);
	}
	return ("Ooopsie");
}
