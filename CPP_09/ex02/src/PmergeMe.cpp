#include "PmergeMe.hpp"

const char* PMerge_bad_input::what() const throw()
{
	return ("Error");
}

void	checkArgument(int argc)
{
	if (argc < 2)
		throw std::runtime_error("Usage is: ./PmergeMe <sequence> <of> <ints> \n");
}

void	validateDigit(std::string word)
{
	for (std::string::iterator it = word.begin(); it != word.end(); it++) {
		if (!isdigit(*it))
			throw PMerge_bad_input();
	}
}
