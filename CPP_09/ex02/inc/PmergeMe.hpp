#ifndef PMERGE_H
# define PMERGE_H

# include <iostream>
# include <sstream>
# include <vector>
# include <list>

void	checkArgument(int argc);
void	validateDigit(std::string word);


class PMerge_bad_input : public std::exception {
	public :
		const char* what() const throw();
	};


#endif
