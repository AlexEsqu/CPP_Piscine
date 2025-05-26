#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

#define TEST_LENGTH 10

int	main()
{
	std::vector<int>	intVector;

	for (int i = 0; i < TEST_LENGTH; i++) {
		intVector.push_back(i + 10);
	}

	std::vector<int>::iterator	result;
	result = easyfind(intVector, 12);
	std::cout << *result << " was found at position ";
	std::cout << std::distance(intVector.begin(), result) << std::endl;

	try {
		result = easyfind(intVector, 0);
		std::cout << *result << " was found at position ";
		std::cout << std::distance(intVector.begin(), result) << std::endl;
	}
	catch (const std::out_of_range& e) {
		std::cout << "Since it doesn't exist in the vector, ";
		std::cout << "0 cannot be found: " << e.what() << std::endl;
	}

	std::list<int>	intList;

	for (int i = 0; i < TEST_LENGTH; i++) {
		intList.push_back(i + 10);
	}

	std::list<int>::iterator	other_result;
	other_result = easyfind(intList, 12);
	std::cout << *other_result << " was found at position ";
	std::cout << std::distance(intList.begin(), other_result) << std::endl;

	try {
		other_result = easyfind(intList, 0);
		std::cout << *other_result << " was found at position ";
		std::cout << std::distance(intList.begin(), other_result) << std::endl;
	}
	catch (const std::out_of_range& e) {
		std::cout << "Since it doesn't exist in the List, ";
		std::cout << "0 cannot be found: " << e.what() << std::endl;
	}

	return 0;
}
