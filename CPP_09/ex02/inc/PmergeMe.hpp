#ifndef PMERGE_H
# define PMERGE_H

# include "StopWatch.hpp"
# include "Color.hpp"
# include "Jacobstahl.hpp"
# include "Pair.hpp"

# include <iostream>
# include <sstream>
# include <vector>
# include <list>
# include <utility>
# include <set>
# include <cstdlib>
# include <algorithm>
# include <assert.h>


struct pend {
	int		value;
	int		smaller_than;
	bool	straggler;
};

class	PmergeMe {

public:

	// ------- CANONICAL FORM -----------------------------------

	PmergeMe();
	~PmergeMe();
	PmergeMe(const PmergeMe& original);
	PmergeMe&	operator=(const PmergeMe& original);

	// ------- LOADING -------------------------------------------

	void	loadDigitsIntoVectorAndList(int argc, char **argv);

	// ------- SORTING -------------------------------------------

	void	vectorMergeInsertSort(std::vector<int>& toSort);
	void	listMergeInsertSort(std::list<int>& toSort);
	void	verifySort();

	// -------- LOGGING ------------------------------------------

	template<typename T>
	void printLogBefore(T& container);
	template<typename T>
	void printLogAfter(T& container, StopWatch& A, StopWatch& B);
	template<typename T>
	bool isSorted(T start_iterator, T end_iterator);

	// ------- STOPWATCH ----------------------------------------

	StopWatch			clockVectorSort;
	StopWatch			clockListSort;

	// ------- VECTOR MERGE INSERT SORT -------------------------

	std::vector<int>	intVector;
	std::list<int>		intList;

	// ------- EFFICIENCY CALCULATOR -------------------------

	size_t				vectorComparisonCount;
	size_t				listComparisonCount;

	class bad_input : public std::exception {
	public :
		const char* what() const throw();
	};

	class bad_sort : public std::exception {
	public :
		const char* what() const throw();
	};

private:

	// ------- VECTOR MERGE INSERT SORT UTILITY -------------------

	void	pairwiseComparison(std::vector<int>& toSort, std::vector<int>& big,
				std::vector<Pair>& small);
	void	insertSmallerByJacobstahlBlocks(std::vector<int>& big, std::vector<Pair>& small);
	void	insertFromJacobstahlDecreasing(size_t start, size_t end,
				std::vector<int>& big, std::vector<Pair>& small);
	void	binaryInsert(std::vector<int>& vector, int value, size_t len);
	void	updateSmallerPosition(std::vector<int>& mainVector, std::vector<Pair>& pendVector);

	// ------- LIST MERGE INSERT SORT UTILITY -----------------------

	void	pairwiseComparison(std::list<int>& toSort, std::list<int>& big,
				std::list<Pair>& small);
	void	insertSmallerByJacobstahlBlocks(std::list<int>& big, std::list<Pair>& small);
	void	insertFromJacobstahlDecreasing(size_t start, size_t end,
				std::list<int>& big, std::list<Pair>& small);
	void	binaryInsert(std::list<int>& list, int value, size_t len);
	void	updateSmallerPosition(std::list<int>& big, std::list<Pair>& small);

};

# include "Log.tpp"

/*

SOURCE : the Merge Insertion Algorithm
As described on The Art Of Programming III p.184 and following,
quoting the method discovered by Lester Ford, Jr and Selmer Johnson:

To sort 21 elements:

i)		PAIRWISE COMPARISON

		" Make pairwise comparison of ⌊n/2⌋ disjoint pair of element.
		If n is odd, leave one element out.
		`K1 : K2, K3 : K4, K5 : K6, ... , K19 : K20,       K21` "

		=> Make pairs, compare them, leave straggler out


ii)		RECURIVELY SORT THE BIGGER OF THE PAIR

		Sort the ⌊n/2⌋ larger number found in step (i) by merge insertion.
		Name the elements a1, a2, a3, ... , a_⌊n/2⌋ and b1, b2, b3, ... , b_⌊n/2⌋ as in:

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

		=> Recursively sort the main chain of bigger numbers, remembering to which they are bigger


iii)	BINARY INSERT THE SMALLER OF THE PAIR USING JACOBSTAHL

		" Insert the remaining bs into the main chain, using binary insertion,
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
		where G represents the amount of work involved in step (iii)."

		=> Use each number in the Jacobstahl suite (sequence t in Knuth's text) as indice
		For each indice in Jacobstahl, binary insert first b[t] into main.begin() - main[t]
		Because b[t] cannot be bigger than any numer in the main chain bigger than a[t]
		Then insert b[t - 1] into somewhere between main.begin() - main[t - 1]
		Then insert b[t - 2] into somewhere between main.begin() - main[t - 2]
		etc.
		Until you reach indices already merged


		straggler left out = bj for j > [n/2]

*/




#endif
