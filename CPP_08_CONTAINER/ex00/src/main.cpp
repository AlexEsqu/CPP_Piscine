#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

void	testVector(int needle, int absent, int test_len)
{
	std::cout << "\nVECTORS" << std::endl;
	std::cout << "Let's create a vector and fill it with values:\n";
	std::vector<int>	intVector;
	for (int i = 0; i < test_len; i++) {
		intVector.push_back(i + 10);
	}
	printContainer(intVector);

	std::cout << "\nWe can use easyfind to find the position of value ";
	std::cout << needle << ":\n";
	std::vector<int>::iterator	result;
	result = easyfind(intVector, needle);
	std::cout << *result << " was found at position ";
	std::cout << std::distance(intVector.begin(), result) << std::endl;

	std::cout << "\nSearching a non existing value returns an error:\n";
	try {
		result = easyfind(intVector, absent);
		std::cout << *result << " was found at position ";
		std::cout << std::distance(intVector.begin(), result) << std::endl;
	}
	catch (const std::out_of_range& e) {
		std::cout << "Since it doesn't exist in the vector, " << absent;
		std::cout << " cannot be found: " << e.what() << std::endl;
	}
}

void	testList(int needle, int absent, int test_len)
{
	std::cout << "\nLIST" << std::endl;
	std::cout << "Let's create a list and fill it with values:\n";
	std::list<int>	intList;
	for (int i = 0; i < test_len; i++) {
		intList.push_back(i + 10);
	}
	printContainer(intList);

	std::cout << "\nWe can use easyfind to find the position of value ";
	std::cout << needle << ":\n";
	std::list<int>::iterator	result;
	result = easyfind(intList, needle);
	std::cout << *result << " was found at position ";
	std::cout << std::distance(intList.begin(), result) << std::endl;

	std::cout << "\nSearching a non existing value returns an error:\n";
	try {
		result = easyfind(intList, absent);
		std::cout << *result << " was found at position ";
		std::cout << std::distance(intList.begin(), result) << std::endl;
	}
	catch (const std::out_of_range& e) {
		std::cout << "Since it doesn't exist in the list, " << absent;
		std::cout << " cannot be found: " << e.what() << std::endl;
	}
}

void	testDeque(int needle, int absent, int test_len)
{
	std::cout << "\nDEQUE" << std::endl;
	std::cout << "Let's create a deque and fill it with values:\n";
	std::deque<int>	intDeque;
	for (int i = 0; i < test_len; i++) {
		intDeque.push_back(i + 10);
	}
	printContainer(intDeque);

	std::cout << "\nWe can use easyfind to find the position of value ";
	std::cout << needle << ":\n";
	std::deque<int>::iterator	result;
	result = easyfind(intDeque, needle);
	std::cout << *result << " was found at position ";
	std::cout << std::distance(intDeque.begin(), result) << std::endl;

	std::cout << "\nSearching a non existing value returns an error:\n";
	try {
		result = easyfind(intDeque, absent);
		std::cout << *result << " was found at position ";
		std::cout << std::distance(intDeque.begin(), result) << std::endl;
	}
	catch (const std::out_of_range& e) {
		std::cout << "Since it doesn't exist in the list, " << absent;
		std::cout << " cannot be found: " << e.what() << std::endl;
	}
}

int	main()
{
	int	needle = 12;
	int	absent = -251;
	int	test_len = 10;

	testVector(needle, absent, test_len);
	testList(needle, absent, test_len);
	testDeque(needle, absent, test_len);

	return 0;
}
