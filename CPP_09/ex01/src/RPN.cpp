#include "RPN.hpp"

const char* RPN_bad_input::what() const throw()
{
	return ("Error");
}

void	checkArgument(int argc)
{
	if (argc != 2) {
		throw std::runtime_error("Proper usage is : ./RPN \"operations to evaluate\"");
	}
}

void	validateWord(std::string word)
{
	// Inputted words cannot be longer as one character
	if (word.size() > 1)
		throw RPN_bad_input();

	// Input can only be numbers or operands
	if (!isdigit(word[0]) && !strchr(SUPPORTED_OPERATORS, word[0]))
		throw RPN_bad_input();
}

int	evaluateOperator(std::stack<int>& operand, char sign)
{
	if (operand.size() < 2)
		throw RPN_bad_input();

	// Copying then taking out the digits from the stack
	int		op2 = operand.top();
	operand.pop();
	int		op1 = operand.top();
	operand.pop();

	switch (sign) {
		case ('+'):
			return (op1 + op2);
		case ('-'):
			return (op1 - op2);
		case ('*'):
			return (op1 * op2);
		case ('/'):
			if (op2 == 0)
				throw RPN_bad_input();
			return (op1 / op2);
		default:
			throw RPN_bad_input();
	}
}

void	addDigitToStack(std::stack<int>& stack, char digit)
{
	#ifdef DEBUG
	std::cout << "Adding " << digit << " to the stack\n";
	#endif

	int	operand = digit - '0';
	stack.push(operand);
}

void	useOperatorOnStack(std::stack<int>& stack, char sign)
{
	#ifdef DEBUG
	std::cout << "Evaluating " << sign << "\n";
	#endif

	int result = evaluateOperator(stack, sign);
	stack.push(result);
}
