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
	bool	hasStraggler = (toSort.size() % 2 != 0);
	if (hasStraggler) {
		pend p;
		p.value = *(--toSort.end());
		p.smaller_than = 0;
		p.straggler = true;
		small.push_back(p);
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
		pend p;
		p.smaller_than = *curr;
		p.value = *next;
		small.push_back(p);
	}

}

void	PmergeMe::insertFromJacobstahlDecreasing(size_t start, size_t end,
			std::list<int>& big, std::list<pend>& small)
{
	std::list<pend>::iterator current = small.begin();
	std::list<pend>::iterator ending = small.begin();
	std::advance(current, start);
	std::advance(ending, end);

	// starting at a JAcobstahl, going downward, binary insert in
	// at most main[0] - main[smol's bigger]
	for (; current != ending; current--) {

		if (current == small.begin())
			break; // skipped since already done

		if (current->straggler)
			binaryInsert(big, current->value, big.size());
		else
		{
			std::list<int>::iterator bigger = std::find(big.begin(), big.end(), current->smaller_than);
			size_t	pos = std::distance(big.begin(), bigger);
			binaryInsert(big, current->value, pos);
		}

	}
}

/*
* insert start of S the element paired with first and smallest element of S
* insert remaining n/2 - 1 elements of X \ S into S one at a time using
* binary search and subsequence of S (Jacobstahl) to determine position
*/
void	PmergeMe::insertSmallerByJacobstahlBlocks(std::list<int>& big, std::list<pend>& small)
{
	// smaller than the smallest big is safe to insert at begin of the chain
	big.insert(big.begin(), small.begin()->value);
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

	// if small.size() is not a Jacobstahl number, need to insert the remaining pend
	size_t	end = 0;
	if (jacobStahlIndex > 0)
		end = JACOBSTHAL_SUITE[jacobStahlIndex - 1];
	insertFromJacobstahlDecreasing(small.size() - 1, end, big, small);
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
	insertSmallerByJacobstahlBlocks(big, small);

	toSort = big;

	clockListSort.stop();
}
