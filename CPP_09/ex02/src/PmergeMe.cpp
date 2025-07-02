#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
	: _vectorComparisonCount(0)
	, _listComparisonCount(0)
{
	#ifdef PRINT
		std::cout << GREEN << "[PmergeMe] Calling Constructor";
		std::cout << STOP_COLOR << std::endl;
	#endif
}

PmergeMe::~PmergeMe()
{
	#ifdef PRINT
		std::cout << RED << "[PmergeMe] Calling Destructor";
		std::cout << STOP_COLOR << std::endl;
	#endif
}

PmergeMe::PmergeMe(const PmergeMe& original)
{
	*this = original;
}

PmergeMe&	PmergeMe::operator=(const PmergeMe& original)
{
	if (this != &original)
	{
		_intList = original._intList;
		_intVector = original._intVector;
		_vectorComparisonCount = original._vectorComparisonCount;
		_listComparisonCount = original._listComparisonCount;
	}
	return (*this);
}
