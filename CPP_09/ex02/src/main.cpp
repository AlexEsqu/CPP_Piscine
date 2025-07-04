#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	try {
		PmergeMe	Sorter;

		Sorter.loadDigitsIntoVectorAndList(argc, argv);

		Sorter.printLogBefore(Sorter.intList);

		Sorter.clockListSort.start();
		Sorter.listMergeInsertSort(Sorter.intList);
		Sorter.clockListSort.stop();

		Sorter.clockVectorSort.start();
		Sorter.vectorMergeInsertSort(Sorter.intVector);
		Sorter.clockVectorSort.stop();

		Sorter.verifySort();

		Sorter.printLogAfter(Sorter.intList, Sorter.clockVectorSort, Sorter.clockListSort);
	}

	catch (std::exception& e) {
		std::cerr << e.what() << "\n";
	}

	return (0);
}
