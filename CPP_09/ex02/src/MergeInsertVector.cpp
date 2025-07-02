#include "PmergeMe.hpp"

void	PmergeMe::vectBinaryInsert(std::vector<int>& vector, int value, size_t len)
{
	size_t	left = 0;
	size_t right = len;

	while (left < right)
	{
		size_t mid = left + (right - left) / 2;
		if (value < vector[mid])
			right = mid;
		else
			left = mid + 1;
	}
	vector.insert(vector.begin() + left, value);
}

void	PmergeMe::pairwiseComparison(std::vector<int>& toSort, std::vector<int>& big,
		std::vector<pend>& small)
{
	std::vector<int>::iterator	end = toSort.end();
	bool	hasStraggler = false;
	if (toSort.size() % 2 != 0) {
		end--;
		hasStraggler = true;
	}

	for (std::vector<int>::iterator i = toSort.begin(); i != end; i += 2)
	{
		if (*i < *(i + 1))
			std::iter_swap(i, (i + 1));
		big.push_back(*i);
		pend p;
		p.value = *(i + 1);
		p.smaller_than = *i;
		small.push_back(p);
	}
}

void	PmergeMe::insertPendingChain(std::vector<int>& big, std::vector<pend>& small)
{
	big.insert(big.begin(), small[0].value);
	for (std::vector<pend>::iterator it = small.begin() + 1; it != small.end(); it++) {
		std::vector<int>::iterator bigger = std::find(big.begin(), big.end(), it->smaller_than);
		size_t pos = std::distance(big.begin(), bigger);
		vectBinaryInsert(big, it->value, pos);
	}
}

void	PmergeMe::insertStraggler(std::vector<int>& toSort, std::vector<int>& result)
{
	if (toSort.size() % 2 != 0)
		vectBinaryInsert(result, *(toSort.end() - 1), result.size());
}


void	PmergeMe::vectorMergeInsertSort(std::vector<int>& intVector)
{
	vectorSort.start();

	if (intVector.size() <= 1)
		return;

	std::vector<int>	big;
	std::vector<pend>	small;

	// Pair up and order the pairs
	pairwiseComparison(intVector, big, small);

	// recursively sort big
	vectorMergeInsertSort(big);

	// insert start of S the element paired with first and smallest element of S
	// insert remaining n/2 - 1 elements of X \ S into S one at a time using
	// binary search and subsequence of S (Jacobstahl) to determine position
	insertPendingChain(big, small);

	insertStraggler(intVector, big);

	intVector = big;

	vectorSort.stop();
}


