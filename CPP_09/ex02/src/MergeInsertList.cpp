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
		std::list<pend>& small)
{
	std::list<int>::iterator	end = toSort.end();
	bool	hasStraggler = false;
	if (toSort.size() % 2 != 0) {
		end--;
		hasStraggler = true;
	}

	for (std::list<int>::iterator curr = toSort.begin(); curr != end; std::advance(curr, 2))
	{
		std::list<int>::iterator next = curr;
		std::advance(next, 1);
		listComparisonCount++;
		if (*curr < *next)
			std::iter_swap(curr, next);
		big.push_back(*curr);
		pend p;
		p.smaller_than = *curr;
		p.value = *next;
		small.push_back(p);
	}

}

// insert start of S the element paired with first and smallest element of S
// insert remaining n/2 - 1 elements of X \ S into S one at a time using
// binary search and subsequence of S (Jacobstahl) to determine position
void	PmergeMe::insertPendingChain(std::list<int>& big, std::list<pend>& small)
{
	big.insert(big.begin(), small.begin()->value);
	for (std::list<pend>::iterator it = ++small.begin(); it != small.end(); it++) {
		std::list<int>::iterator bigger = std::find(big.begin(), big.end(), it->smaller_than);
		size_t pos = std::distance(big.begin(), bigger);
		binaryInsert(big, it->value, pos);
	}
}

void	PmergeMe::insertStraggler(std::list<int>& toSort, std::list<int>& result)
{
	if (toSort.size() % 2 != 0)
		binaryInsert(result, toSort.back(), result.size());
}


void	PmergeMe::listMergeInsertSort(std::list<int>& toSort)
{
	clockListSort.start();

	if (toSort.size() <= 1)
		return;

	std::list<int>	big;
	std::list<pend>	small;

	// Pair up and order the pairs
	pairwiseComparison(toSort, big, small);

	// recursively sort big
	listMergeInsertSort(big);

	// binary insert smallers using Jacobstahl
	insertPendingChain(big, small);

	insertStraggler(toSort, big);

	toSort = big;

	clockListSort.stop();
}
