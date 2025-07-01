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

void	loadDigitsIntoVectorAndList(int argc, char **argv,
		std::vector<int>& intVector, std::list<int>& intList);

void	MergeInsertSort(std::vector<int>& intVector);

void	MergeInsertSort(std::list<int>& intList);



class PMerge_bad_input : public std::exception {
	public :
		const char* what() const throw();
};

#endif
