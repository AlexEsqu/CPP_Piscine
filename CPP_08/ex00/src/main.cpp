#include <iostream>
#include <vector>
#include "easyfind.hpp"

#define VECTOR_LENGTH 10

int	main()
{
	std::vector<int>	intVector;

	for (int i = 0; i < VECTOR_LENGTH; i++) {
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

	return 0;
}
