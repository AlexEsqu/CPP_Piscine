#include "PmergeMe.hpp"

void	binaryInsert(std::vector<int>& vector, int value, size_t len)
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


void	pairwiseComparison(std::vector<int>& original, std::vector<int>& big,
		std::vector<int>& small)
{
	std::vector<int>::iterator	end = original.end();
	bool	hasStraggler = false;
	if (original.size() % 2 != 0) {
		end--;
		hasStraggler = true;
	}

	for (std::vector<int>::iterator i = original.begin(); i != end; i += 2)
	{
		if (*i < *(i + 1))
			std::iter_swap(i, (i + 1));
		big.push_back(*i);
		small.push_back(*(i + 1));
	}

	if (hasStraggler)
		small.push_back(*end);

	std::cout << "Big is [";
	printContainer(big);
	std::cout << "]\nSmall is [";
	printContainer(small);
	std::cout << "]\n";

}

void	insertstraggler(std::vector<int>& intVector, std::vector<int>& result)
{
	if (intVector.size() % 2 != 0)
		binaryInsert(result, *(intVector.end() - 1), result.size());
}





/*
Following the Merge Insertion Algorithm
As described on The Art Of Programming III p.185:

i)		Make pairwise comparison of ⌊n/2⌋ disjoint pair of element.
		If n is odd, leave one element out.

ii)		Sort the ⌊n/2⌋ larger number found in step (i) by merge insertion.

iii)	Name the elements a1, a2, a3, ... , a_⌊n/2⌋ and b1, b2, b3, ... , b_⌊n/2⌋ as in:

```
	a1  a2  a3  a4  a5  a6  a7  a8  a9  a10
	o-->o-->o-->o-->o-->o-->o-->o-->o-->o
   /   /   /   /   /   /   /   /   /   /
  /   /   /   /   /   /   /   /   /   /
 o   o   o   o   o   o   o   o   o   o      o
b1  b2  b3  b4  b5  b6  b7  b8  b9  b10    b11
```
		where a1 <= a2 <= ... <= a_⌊n/2⌋ and bi <= ai for 1 <= i <= ⌊n/2⌋;

		Call b1 and the a's the "main chain."

		Insert the remaining b's into the main chain, using binary insertion,
		in the following order, leaving out all b_j for j > ⌈n/2⌉:
```
			b3, b2; b5, b4; b11, b10; ..., b6; ...; b_t_k, b_(t(_k)-1), ..., b_(t_(k-1)+1); ....
```
		We wish to define the sequence (t1, t2, t3, t4, ...) = (1, 3, 5, 11, ...)
		in such a way that each of b_t_k, b_(t(_k)-1), ..., b_(t_(k-1)+1) can be
		inserted into the main chain with at most k comparisons.

		We obtain the diagram
```
x1  x2      x2_t_(k-1)   a_(t_(k-1)+1)   a_(t_(k-1)+2)   a_(t(_k)-1)
o-->o------>o--- - - --->o-------------->o----- - - ----o - - - -
                        /               /              /              /
                       /               /              /              /
                      o               o              o              o
                    b_t_(k-1)+1     b_t_(k-1)+2     b_(t(_k)-1)    b_t_k
```
		Where the main chain up to and including a_(t(_k)-1) contains
		2t_(k-1) + (t_k - t_(k-1) - 1) elements. This number must be less than 2^k;
		our best bet is to set it equal to 2^k so that `t_(k-1) + t_k = 2^k`

		Let F(n) be the number of comparisons required to sort n elements by merge insertion.
		Clearly,
		`F(n) = ⌊n/2⌋ + F(⌊n/2⌋) + G(⌊n/2⌋)`
		where G represents the amount of work involved in step (iii).

		[...]

		Trybula and Czen may have independently discovered the method of merge
		insertion, which was published soon afterwards by Ford and Johnson.

*/
void	MergeInsertSort(std::vector<int>& intVector)
{
	if (intVector.size() <= 1)
		return;

	std::vector<int>	big, small;

	// Pair up and order the pairs
	pairwiseComparison(intVector, big, small);

	// recursively sort big
	MergeInsertSort(big);

	//insert start of S the element paired with first and smallest element of S
	std::vector<int>	result = big;
	result.insert(result.begin(), small[0]);

	//insert remaining n/2 - 1 elements of X \ S into S one at a time using
	// binary search and subsequence of S (Jacobstahl) to determine position


	insertstraggler(intVector, result);

	intVector = result;
}

void	MergeInsertSort(std::list<int>& intList)
{
	if (intList.size() <= 1)
		return;

	// intList.sort();

	// bool hasStraggler = (intList.size() % 2 != 0);

	// std::list<int> main, pend;

	// //Group into n/2 pair of elements and set straggler
	// //perform n/2 comparison to determine bigger in each pair

	// //recursively sort n/2 larger element from each pair into sorted S sequence
	// MergeInsertSort(main);


	//insert start of S the element paired with first and smallest element of S
	//inster remaining n/2 - 1 elements of X \ S into S one at a time using binary search and using subsequence of S to determine position
}
