#include "RPN.hpp"

int	main(int argc, char **argv)
{
	try
	{
		checkArgument(argc);

		std::stringstream	stream(argv[1]);
		std::string			word;
		std::stack<int>		stack;

		while (stream >> word)
		{
			validateWord(word);

			if (isdigit(word[0]))
				addDigitToStack(stack, word[0]);

			else
				useOperatorOnStack(stack, word[0]);
		}
		std::cout << stack.top() << "\n";
	}
	catch (std::exception& e) {
		std::cerr << e.what() << "\n";
	}
	return (0);
}
