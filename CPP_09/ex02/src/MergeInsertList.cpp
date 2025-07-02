#include "PmergeMe.hpp"

static void	binaryInsert(std::list<int>& list, int value, size_t len)
{
	size_t	left = 0;
	size_t right = len;

	std::list<int>::iterator itTarget = list.begin();
	while (left < right)
	{
		size_t mid = left + (right - left) / 2;
		std::list<int>::iterator itMid = list.begin();
		std::advance(itMid, mid);
		if (value < *itMid)
			right = mid;
		else
			left = mid + 1;
	}
	std::advance(itTarget, left);
	list.insert(itTarget, value);
}


static void	pairwiseComparison(std::list<int>& original, std::list<int>& big,
		std::list<pend>& small)
{
	std::list<int>::iterator	end = original.end();
	bool	hasStraggler = false;
	if (original.size() % 2 != 0) {
		end--;
		hasStraggler = true;
	}

	for (std::list<int>::iterator curr = original.begin(); curr != end; std::advance(curr, 2))
	{
		std::list<int>::iterator next = curr;
		std::advance(next, 1);
		if (*curr < *next)
			std::iter_swap(curr, next);
		big.push_back(*curr);
		pend p;
		p.smaller_than = *curr;
		p.value = *next;
		small.push_back(p);
	}

	// std::cout << "Big is [";
	// printContainer(big);
	// std::cout << "]\nSmall is [";
	// // printContainer(small);
	// std::cout << "]\n";

}

static void	insertstraggler(std::list<int>& intList, std::list<int>& result)
{
	if (intList.size() % 2 != 0)
		binaryInsert(result, intList.back(), result.size());
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
void	PmergeMe::listMergeInsertSort(std::list<int>& intList)
{
	listSort.start();

	if (intList.size() <= 1)
		return;

	std::list<int>	big;
	std::list<pend>	small;

	// Pair up and order the pairs
	pairwiseComparison(intList, big, small);

	// recursively sort big
	listMergeInsertSort(big);

	// insert start of S the element paired with first and smallest element of S
	big.insert(big.begin(), small.begin()->value);

	// insert remaining n/2 - 1 elements of X \ S into S one at a time using
	// binary search and subsequence of S (Jacobstahl) to determine position
	for (std::list<pend>::iterator it = ++small.begin(); it != small.end(); it++) {
		std::list<int>::iterator bigger = std::find(big.begin(), big.end(), it->smaller_than);
		size_t pos = std::distance(big.begin(), bigger);
		binaryInsert(big, it->value, pos);
	}

	insertstraggler(intList, big);

	intList = big;

	listSort.stop();
}
