#include "PmergeMe.hpp"

const char* PMerge_bad_input::what() const throw()
{
	return ("Error");
}

static void	checkArgument(int argc)
{
	if (argc < 2)
		throw std::runtime_error("Usage is: ./PmergeMe <sequence> <of> <ints> \n");
}

// Filters out non digit characters, including minus signs
static void	validateDigit(std::string word)
{
	for (std::string::iterator it = word.begin(); it != word.end(); it++) {
		if (!isdigit(*it))
			throw PMerge_bad_input();
	}
}

// Errors from duplicates can be managed at out discretion per subject p.13
static void	dissalowDiplicatesDigit(int digit, std::set<int>& intSet)
{
	if (std::find(intSet.begin(), intSet.end(), digit) != intSet.end())
		throw PMerge_bad_input();
	intSet.insert(digit);
}

void	loadDigitsIntoVectorAndList(int argc, char **argv,
		std::vector<int>& intVector, std::list<int>& intList)
{
	checkArgument(argc);
	std::set<int>	intSet; // using a set to quickly check for duplicates
	for (int i = 1; i < argc; i++)
	{
		validateDigit(argv[i]);
		int	digit = std::atoi(argv[i]);
		dissalowDiplicatesDigit(digit, intSet);
		intList.push_back(digit);
		intVector.push_back(digit);
	}
}
