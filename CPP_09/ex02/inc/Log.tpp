#include "StopWatch.hpp"

template<typename T>
void printContainer(T& container)
{
	for (typename T::iterator iter = container.begin(); iter != container.end(); iter++)
	{
		if (iter != container.begin())
			std::cout << " ";
		std::cout << *iter;
	}
}


template<typename T>
void PmergeMe::printLogBefore(T& container)
{
	std::cout << "Before: ";
	printContainer(container);
	std::cout << std::endl;
}

template<typename T>
void PmergeMe::printLogAfter(T& container, StopWatch& A, StopWatch& B)
{
	std::cout << "After:  ";
	printContainer(container);
	std::cout << "\n";
	std::cout << "Time to process a range of " << container.size();
	std::cout << " with std::" << A.getName() << " : ";
	std::cout << std::setprecision(6) << A.getTimeInUsec() << " us\n";
	#ifdef PRINT
	std::cout << SOFT_BLUE << "Vector comparisons: " << vectorComparisonCount << RESET << "\n";
	#endif
	std::cout << "Time to process a range of " << container.size();
	std::cout << " with std::" << B.getName() << " : ";
	std::cout << std::setprecision(6) << B.getTimeInUsec() << " us\n";
	#ifdef PRINT
	std::cout << SOFT_BLUE << "List   comparisons: " << listComparisonCount << RESET << "\n";
	#endif

}

