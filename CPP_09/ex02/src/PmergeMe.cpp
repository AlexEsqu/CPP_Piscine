#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
	: vectorSort("vector")
	, listSort("list  ")
	, _vectorComparisonCount(0)
	, _listComparisonCount(0)
{
	#ifdef PRINT
		std::cout << SOFT_GREEN << "[PmergeMe] Constructor\n" << RESET;
	#endif
}

PmergeMe::~PmergeMe()
{
	#ifdef PRINT
		std::cout << RED << "[PmergeMe] Destructor\n" << RESET;
	#endif
}

PmergeMe::PmergeMe(const PmergeMe& original)
{
	#ifdef PRINT
		std::cout << GREEN << "[PmergeMe] Copy Constructor\n" << RESET;
	#endif
	*this = original;
}

PmergeMe&	PmergeMe::operator=(const PmergeMe& original)
{
	#ifdef PRINT
		std::cout << GREEN << "[PmergeMe] Copy Assignement\n" << RESET;
	#endif
	if (this != &original)
	{
		intList = original.intList;
		intVector = original.intVector;
		_vectorComparisonCount = original._vectorComparisonCount;
		_listComparisonCount = original._listComparisonCount;
	}
	return (*this);
}
