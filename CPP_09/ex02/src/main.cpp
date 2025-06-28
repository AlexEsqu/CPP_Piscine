#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	try {
		std::list<int>		intList;
		std::vector<int>	intVector;

		loadDigitsIntoVectorAndList(argc, argv, intVector, intList);
		printLog(intList, false);
		TournamentSort(intList);
		//TournamentSortVector(intVector);
		printLog(intList, true);
	}

	catch (std::exception& e) {
		std::cerr << e.what() << "\n";
	}

	return (0);
}
