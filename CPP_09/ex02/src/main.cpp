#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	try {
		std::list<int>		intList;
		std::vector<int>	intVector;

		loadDigitsIntoVectorAndList(argc, argv, intVector, intList);
		printLog(intList, false);
		//MergeInsertSort(intList);
		MergeInsertSort(intVector);
		printLog(intList, true);
	}

	catch (std::exception& e) {
		std::cerr << e.what() << "\n";
	}

	return (0);
}
