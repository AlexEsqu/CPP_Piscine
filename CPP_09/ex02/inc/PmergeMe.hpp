#ifndef PMERGE_H
# define PMERGE_H

# include <iostream>
# include <sstream>
# include <vector>
# include <list>
# include <cstdlib>

void	checkArgument(int argc);
void	validateDigit(std::string word);
void	loadDigitsIntoVectorAndList(int argc, char **argv, std::vector<int>& intVector, std::list<int>& intList);


class PMerge_bad_input : public std::exception {
	public :
		const char* what() const throw();
	};


template<typename T>
void printContainer(T& container) {
	for (typename T::iterator iter = container.begin(); iter != container.end(); iter++)
	{
		if (iter != container.begin())
			std::cout << " ";
		std::cout << *iter;
	}
}


#endif
