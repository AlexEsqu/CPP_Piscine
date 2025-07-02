#ifndef PMERGE_H
# define PMERGE_H

# include "StopWatch.hpp"
# include "Log.hpp"

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

	PmergeMe();
	~PmergeMe();
	PmergeMe(const PmergeMe& original);
	PmergeMe&	operator=(const PmergeMe& original);

	void	loadDigitsIntoVectorAndList(int argc, char **argv);
	void	MergeInsertSort(std::vector<int>& intVector);
	void	MergeInsertSort(std::list<int>& intList);

	StopWatch	vectorSort;
	StopWatch	listSort;

	class bad_input : public std::exception {
	public :
		const char* what() const throw();
	};

private:

	size_t				_vectorComparisonCount;
	size_t				_listComparisonCount;
	std::vector<int>	_intVector;
	std::list<int>		_intList;

};







#endif
