#include "PmergeMe.hpp"

void	PmergeMe::binaryInsert(std::vector<int>& vector, int value, size_t len)
{
	size_t	left = 0;
	size_t right = len;

	while (left < right)
	{
		size_t mid = left + (right - left) / 2;
		vectorComparisonCount++;
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
	bool	hasStraggler = (toSort.size() % 2 != 0);
	if (hasStraggler) {
		pend p;
		p.value = toSort[toSort.size() - 1];
		p.smaller_than = 0;
		p.straggler = true;
		small.push_back(p);
		end--;
	}

	if (toSort.size() <= 1)
			return;

	for (std::vector<int>::iterator i = toSort.begin(); i != end; i += 2)
	{
		vectorComparisonCount++;
		if (*i < *(i + 1))
			std::iter_swap(i, (i + 1));
		big.push_back(*i);
		pend p;
		p.value = *(i + 1);
		p.smaller_than = *i;
		p.straggler = false;
		small.push_back(p);
	}
}

void	PmergeMe::insertFromJacobstahlDecreasing(size_t start, size_t end,
			std::vector<int>& big, std::vector<pend>& small)
{
	// starting at this indice, going downward, binary insert in at most main[0] - main[smol's bigger]
	for (size_t indice = start; indice > end; indice --) {

		if (indice == 0)
			break; // skipped since already done

		if (small[indice].straggler)
			binaryInsert(big, small[indice].value, big.size());
		else
		{
			std::vector<int>::iterator bigger = std::find(big.begin(), big.end(), small[indice].smaller_than);
			size_t	pos = std::distance(big.begin(), bigger);
			binaryInsert(big, small[indice].value, pos);
		}

	}
}

/*
* insert start of S the element paired with first and smallest element of S
* insert remaining n/2 - 1 elements of X \ S into S one at a time using
* binary search and subsequence of S (Jacobstahl) to determine position
*/
void	PmergeMe::insertSmallerByJacobstahlBlocks(std::vector<int>& big, std::vector<pend>& small)
{
	// smaller than the smallest big is safe to insert at begin of the chain
	big.insert(big.begin(), small[0].value);
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

void	PmergeMe::vectorMergeInsertSort(std::vector<int>& intVector)
{
	clockVectorSort.start();

	if (intVector.size() <= 1)
		return;

	std::vector<int>	big;
	big.reserve(intVector.size());
	std::vector<pend>	small;
	small.reserve(intVector.size());

	// Pair up and order the pairs
	pairwiseComparison(intVector, big, small);

	// recursively sort bigger numbers of the pairs
	vectorMergeInsertSort(big);

	// binary insert smaller numbers using Jacobstahl suite
	insertSmallerByJacobstahlBlocks(big, small);

	intVector = big;

	clockVectorSort.stop();
}


