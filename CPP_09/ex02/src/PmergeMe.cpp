#include "PmergeMe.hpp"


void	groupElementsByPairs(std::vector<int> intVector, bool hasStraggler)
{

}

void	orderEachPair(std::vector<int> intVector)
{

}



void	insertstraggler()
{

}




void	MergeInsertSort(std::vector<int> intVector)
{
	if (intVector.size() <= 1)
		return;

	bool hasStraggler = (intVector.size() % 2 != 0);

	//Group into n/2 pair of elements and set straggler
	//perform n/2 comparison to determine bigger in each pair

	//recursively sort n/2 larger element from each pair into sorted S sequence
	MergeInsertSort(main);

	//insert start of S the element paired with first and smallest element of S
	//inster remaining n/2 - 1 elements of X \ S into S one at a time using binary search and using subsequence of S to determine position
}
