#include "RPN.hpp"

int	main(int argc, char **argv)
{
	try
	{
		checkArgument(argc);
		std::stringstream	stream(argv[1]);
		std::stack<int>		stack;

		for (std::string word; stream >> word;)
		{
			validateWord(word);
			if (isdigit(word[0]))
				addDigitToStack(stack, word[0]);
			else
				useOperatorOnStack(stack, word[0]);
		}

		if (stack.size() != 1)
			throw RPN_bad_input();
		std::cout << stack.top() << "\n";
	}

	catch (std::exception& e) {
		std::cerr << e.what() << "\n";
	}
	return (0);
}
