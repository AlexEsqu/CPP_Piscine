#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	try {
		PmergeMe	Sorter;

		Sorter.loadDigitsIntoVectorAndList(argc, argv);

		Sorter.printLogBefore(Sorter.intList);

		Sorter.listMergeInsertSort(Sorter.intList);

		Sorter.vectorMergeInsertSort(Sorter.intVector);

		Sorter.printLogAfter(Sorter.intVector, Sorter.clockVectorSort, Sorter.clockListSort);
	}

	catch (std::exception& e) {
		std::cerr << e.what() << "\n";
	}

	return (0);
}
