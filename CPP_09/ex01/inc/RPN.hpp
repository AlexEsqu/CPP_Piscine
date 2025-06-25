#ifndef RPN_H
# define RPN_H

# include <iostream>
# include <sstream>
# include <stack>
# include <string>
# include <string.h>

# define SUPPORTED_OPERATORS "+-/*"

void	checkArgument(int argc);
void	validateWord(std::string word);
void	addDigitToStack(std::stack<int>& stack, char digit);
void	useOperatorOnStack(std::stack<int>& stack, char sign);

class RPN_bad_input : public std::exception {
	public :
		const char* what() const throw();
	};

#endif
