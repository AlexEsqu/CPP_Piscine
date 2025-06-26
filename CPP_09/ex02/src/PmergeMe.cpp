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

void	loadDigitsIntoVectorAndList(int argc, char **argv, std::vector<int>& intVector, std::list<int>& intList)
{
	for (int i = 1; i < argc; i++)
	{
		validateDigit(argv[i]);
		int	digit = std::atoi(argv[i]);
		intList.push_back(digit);
		intVector.push_back(digit);
	}
}
