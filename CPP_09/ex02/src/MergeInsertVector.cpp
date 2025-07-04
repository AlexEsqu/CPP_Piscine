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
		std::vector<Pair>& small)
{
	std::vector<int>::iterator	end = toSort.end();
	bool	hasStraggler = (toSort.size() % 2 != 0);
	if (hasStraggler)
		end--;

	if (toSort.size() <= 1)
			return;

	for (std::vector<int>::iterator i = toSort.begin(); i != end; i += 2)
	{
		vectorComparisonCount++;
		if (*i < *(i + 1))
			std::iter_swap(i, (i + 1));
		big.push_back(*i);
		small.push_back(Pair(*i, *(i + 1)));
	}

	if (hasStraggler)
		small.push_back(Pair(toSort[toSort.size() - 1]));
}

void	PmergeMe::insertFromJacobstahlDecreasing(size_t start, size_t end,
			std::vector<int>& main, std::vector<Pair>& pend)
{
	std::cout << "Inserting from " << start << std::endl;

	// starting at this indice, going downward, binary insert in at most main[0] - main[smol's bigger]
	for (size_t indice = start; indice > end; indice --) {

		if (pend[indice].isStraggler())
			binaryInsert(main, pend[indice].getSmall(), main.size());

		else
		{
			std::vector<int>::iterator bigger = std::find(main.begin(), main.end(), pend[indice].getBig());
			size_t	pos = std::distance(main.begin(), bigger);
			binaryInsert(main, pend[indice].getSmall(), pos);
		}
	}
}

/* insert start of S the element paired with first and smallest element of S
* insert remaining n/2 - 1 elements of X \ S into S one at a time using
* binary search and subsequence of S (Jacobstahl) to determine position */
void	PmergeMe::insertSmallerByJacobstahlBlocks(std::vector<int>& main, std::vector<Pair>& pend)
{
	std::cout << "Inserting pend size " << pend.size() << std::endl;

	// smaller than the smallest big is safe to insert at begin of the chain
 	main.insert(main.begin(), pend.begin()->getSmall());
	if (pend.size() <= 1)
		return;

	// Going through the Jacobstahl suite starting at index 2 (3)
	unsigned int jacobStahlIndex = 1;
	while (jacobStahlIndex < JACOBSTHAL_SIZE && JACOBSTHAL_SUITE[jacobStahlIndex] < pend.size() - 1)
	{
		// Insert the smalls block by block, starting at [Jacobstahl number],
		// then inserting the ones before until [Jacobstahl - 1]
		size_t	start = JACOBSTHAL_SUITE[jacobStahlIndex];
		size_t	end = JACOBSTHAL_SUITE[jacobStahlIndex - 1];
		insertFromJacobstahlDecreasing(start, end, main, pend);
		jacobStahlIndex++;
	}

	// if small.size() is not a Jacobstahl number, need to insert the remaining pend
	size_t	end = 0;
	if (jacobStahlIndex > 1)
		end = JACOBSTHAL_SUITE[jacobStahlIndex - 1];
	insertFromJacobstahlDecreasing(pend.size() - 1, end, main, pend);
}

void	PmergeMe::updateSmallerPosition(std::vector<int>& mainVector, std::vector<Pair>& pendVector)
{
	if (pendVector.size() > 1)
	{
		for (size_t i = 0; i < mainVector.size(); i++)
		{
			std::vector<int>::iterator itMain = mainVector.begin() + i;
			std::vector<Pair>::iterator itPend = pendVector.begin() + i;
			std::vector<Pair>::iterator pend = std::find(pendVector.begin(), pendVector.end(), *itMain);
			std::swap(*pend, *itPend);
		}
	}
}

void	PmergeMe::vectorMergeInsertSort(std::vector<int>& toSort)
{
	if (toSort.size() <= 1)
		return;

	std::vector<int>	mainVector;
	mainVector.reserve(toSort.size());
	std::vector<Pair>	pendVector;
	pendVector.reserve(toSort.size());

	// Pair up and order the pairs
	pairwiseComparison(toSort, mainVector, pendVector);

	// recursively sort bigger numbers of the pairs
	vectorMergeInsertSort(mainVector);

	// update the pending chain without comparison, using the sorted main chain
	updateSmallerPosition(mainVector, pendVector);

	// binary insert smaller numbers using Jacobstahl suite
	insertSmallerByJacobstahlBlocks(mainVector, pendVector);

	toSort = mainVector;
}


