#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
	: clockVectorSort("vector")
	, clockListSort("list  ")
	, vectorComparisonCount(0)
	, listComparisonCount(0)
{
	#ifdef PRINT
		std::cout << SOFT_GREEN << "[PmergeMe] Constructor\n" << RESET;
	#endif
}

PmergeMe::~PmergeMe()
{
	#ifdef PRINT
		std::cout << SOFT_RED << "[PmergeMe] Destructor\n" << RESET;
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
		vectorComparisonCount = original.vectorComparisonCount;
		listComparisonCount = original.listComparisonCount;
	}
	return (*this);
}

const char* PmergeMe::bad_sort::what() const throw()
{
	return ("Error");
}

void	PmergeMe::verifySort()
{
	#ifdef PRINT
	std::cout << SOFT_ORANGE << "Vector: ";
	printContainer(intVector);
	std::cout << SOFT_BLUE << "\nList  : ";
	printContainer(intList);
	std::cout << RESET << "\n";
	#endif

	// if ( !isSorted(intVector.begin(), intVector.end()))
	// 	// || !isSorted(intList.begin(), intList.end()))
	// 	throw bad_sort();
}
