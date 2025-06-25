#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{

	try {
		checkArgument(argc);
		std::list<int>		intList;
		std::vector<int>	intVector;

		for (int i = 0; i < argc; i++)
		{
			validateDigit(argv[i]);



		}
	}

	catch (std::exception& e) {
		std::cerr << e.what() << "\n";
	}

	return (0);
}
