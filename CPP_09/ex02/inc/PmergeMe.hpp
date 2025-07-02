#ifndef PMERGE_H
# define PMERGE_H

# include "StopWatch.hpp"
# include "Log.hpp"
# include "Color.hpp"

# include <iostream>
# include <sstream>
# include <vector>
# include <list>
# include <utility>
# include <set>
# include <cstdlib>
# include <algorithm>


struct pend {
	int		value;
	int		smaller_than;
};

class	PmergeMe {

public:

	// ------- CANONICAL FORM -----------------------------------

	PmergeMe();
	~PmergeMe();
	PmergeMe(const PmergeMe& original);
	PmergeMe&	operator=(const PmergeMe& original);

	// ------- LOADING VALUES -----------------------------------

	void	loadDigitsIntoVectorAndList(int argc, char **argv);

	// ------- VECTOR MERGE INSERT SORT -------------------------

	void	vectorMergeInsertSort(std::vector<int>& toSort);
	void	pairwiseComparison(std::vector<int>& toSort, std::vector<int>& big,
		std::vector<pend>& small);
	void	insertPendingChain(std::vector<int>& big, std::vector<pend>& small);
	void	insertStraggler(std::vector<int>& toSort, std::vector<int>& result);
	void	vectBinaryInsert(std::vector<int>& vector, int value, size_t len);

	// ------- LIST MERGE INSERT SORT ---------------------------

	void	listMergeInsertSort(std::list<int>& intList);
	void	pairwiseComparison();
	void	insertPendingChain();
	void	insertstraggler();
	void	listBinaryInsert(std::list<int>& vector, int value, size_t len);

	// ------- STOPWATCH ----------------------------------------

	StopWatch			vectorSort;
	StopWatch			listSort;

	// ------- VECTOR MERGE INSERT SORT -------------------------

	std::vector<int>	intVector;
	std::list<int>		intList;

	class bad_input : public std::exception {
	public :
		const char* what() const throw();
	};

private:

	size_t				_vectorComparisonCount;
	size_t				_listComparisonCount;

	


};


/*

SOURCE : the Merge Insertion Algorithm
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




#endif
