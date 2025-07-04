#include "PmergeMe.hpp"

void	PmergeMe::binaryInsert(std::list<int>& list, int value, size_t len)
{
	size_t	left = 0;
	size_t right = len;

	std::list<int>::iterator itTarget = list.begin();
	while (left < right)
	{
		size_t mid = left + (right - left) / 2;
		std::list<int>::iterator itMid = list.begin();
		std::advance(itMid, mid);
		listComparisonCount++;
		if (value < *itMid)
			right = mid;
		else
			left = mid + 1;
	}
	std::advance(itTarget, left);
	list.insert(itTarget, value);
}

void	PmergeMe::pairwiseComparison(std::list<int>& toSort, std::list<int>& big,
		std::list<Pair>& small)
{
	std::list<int>::iterator	end = toSort.end();
	bool						hasStraggler = (toSort.size() % 2 != 0);
	if (hasStraggler) {
		end--;
	}

	if (toSort.size() <= 1)
		return;

	for (std::list<int>::iterator curr = toSort.begin(); curr != end; std::advance(curr, 2))
	{
		std::list<int>::iterator next = curr;
		std::advance(next, 1);
		listComparisonCount++;
		if (*curr < *next)
			std::iter_swap(curr, next);
		big.push_back(*curr);
		small.push_back(Pair(*curr, *next));
	}

	if (hasStraggler)
		small.push_back(Pair(*(--toSort.end())));
}

void	PmergeMe::insertFromJacobstahlDecreasing(size_t start, size_t end,
			std::list<int>& big, std::list<Pair>& small)
{
	std::list<Pair>::iterator current = small.begin();
	std::list<Pair>::iterator ending = small.begin();
	std::advance(current, start);
	std::advance(ending, end);

	// starting at a Jacobstahl, going downward, binary insert in
	// at most main[0] - main[smol's bigger]
	for (; current != ending; current--) {

		if (current->isStraggler())
			binaryInsert(big, current->getSmall(), big.size());
		else
		{
			std::list<int>::iterator bigger = std::find(big.begin(), big.end(), current->getBig());
			size_t	pos = std::distance(big.begin(), bigger);
			binaryInsert(big, current->getSmall(), pos);
		}
	}
}

/*
* insert start of S the element paired with first and smallest element of S
* insert remaining n/2 - 1 elements of X \ S into S one at a time using
* binary search and subsequence of S (Jacobstahl) to determine position
*/
void	PmergeMe::insertSmallerByJacobstahlBlocks(std::list<int>& big, std::list<Pair>& small)
{
	// smaller than the smallest big is safe to insert at begin of the chain
	big.insert(big.begin(), small.begin()->getSmall());
	if (small.size() <= 1)
		return;

	// Going through the Jacobstahl suite starting at index 1
	unsigned int jacobStahlIndex = 1;
	while (jacobStahlIndex < JACOBSTHAL_SIZE && JACOBSTHAL_SUITE[jacobStahlIndex] < small.size())
	{
		// Insert the smalls block by block, starting at [Jacobstahl number],
		// then inserting the ones before until [Jacobstahl - 1]
		size_t	start = JACOBSTHAL_SUITE[jacobStahlIndex];
		size_t	end = JACOBSTHAL_SUITE[jacobStahlIndex - 1];
		insertFromJacobstahlDecreasing(start, end, big, small);
		jacobStahlIndex++;
	}

	// if small.size() is not a Jacobstahl number, need to insert the remaining
	// pend from [Jacobstahl] to size()
	size_t	end = 0;
	if (jacobStahlIndex > 0)
		end = JACOBSTHAL_SUITE[jacobStahlIndex - 1];
	insertFromJacobstahlDecreasing(small.size() - 1, end, big, small);
}

void	PmergeMe::updateSmallerPosition(std::list<int>& big, std::list<Pair>& small)
{
	if (small.size() > 1)
	{
		for (size_t i = 0; i < big.size(); i++)
		{
			std::list<int>::iterator itMain = big.begin();
			std::advance(itMain, i);
			std::list<Pair>::iterator itPend = small.begin();
			std::advance(itPend, i);
			std::list<Pair>::iterator pend = std::find(small.begin(), small.end(), *itMain);
			std::swap(*pend, *itPend);
		}
	}
}

void	PmergeMe::listMergeInsertSort(std::list<int>& toSort)
{
	if (toSort.size() <= 1)
		return;

	std::list<int>	big;
	std::list<Pair>	small;

	// Pair up and order the pairs
	pairwiseComparison(toSort, big, small);

	// recursively sort big
	listMergeInsertSort(big);

	updateSmallerPosition(big, small);

	// binary insert smallers using Jacobstahl
	insertSmallerByJacobstahlBlocks(big, small);

	toSort = big;
}
