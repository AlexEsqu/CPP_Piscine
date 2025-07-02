#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	try {
		PmergeMe	Sorter;

		Sorter.loadDigitsIntoVectorAndList(argc, argv);

		printLogBefore(Sorter.intList);

		Sorter.listMergeInsertSort(Sorter.intList);

		Sorter.vectorMergeInsertSort(Sorter.intVector);

		printLogAfter(Sorter.intVector, Sorter.vectorSort, Sorter.listSort);
	}

	catch (std::exception& e) {
		std::cerr << e.what() << "\n";
	}

	return (0);
}
