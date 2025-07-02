#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	try {
		PmergeMe	Sorter();

		Sorter.loadDigitsIntoVectorAndList(argc, argv);
		printLogBefore(intList);
		StopWatch	ChronoList("list");
		StopWatch	ChronoVect("vector");
		ChronoList.start();
		MergeInsertSort(intList);
		ChronoList.stop();
		ChronoVect.start();
		MergeInsertSort(intVector);
		ChronoVect.stop();
		printLogAfter(intVector, ChronoList, ChronoVect);
	}

	catch (std::exception& e) {
		std::cerr << e.what() << "\n";
	}

	return (0);
}
