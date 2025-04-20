#include <iostream>
#include <string>
#include <cstdlib>

enum e_prompt_types {
	ALPHA	= 0,
	NUM		= 1,
};

std::string	prompt( std::string prompt, e_prompt_types mode );
