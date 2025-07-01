#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	try {
		std::list<int>		intList;
		std::vector<int>	intVector;

		loadDigitsIntoVectorAndList(argc, argv, intVector, intList);
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
