#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{

	try {
		checkArgument(argc);
		std::list<int>		intList;
		std::vector<int>	intVector;

		loadDigitsIntoVectorAndList(argc, argv, intVector, intList);
		std::cout << "Before: ";
		printContainer<std::list <int> >(intList);
		std::cout << "\nAfter:  ";
		

	}

	catch (std::exception& e) {
		std::cerr << e.what() << "\n";
	}

	return (0);
}
