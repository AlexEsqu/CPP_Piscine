#include <iostream>
#include <string>
#include <sstream>
#include "Array.hpp"

#define ARRAY_LEN 5

int	main()
{
	std::cout << "EMPTY ARRAY TEST" << std::endl;
	std::cout << "Let's initialize an int array without any length\n";
	Array	<int>arrayEmpty;

	std::cout << "We can check its size : " << arrayEmpty.size() << std::endl;

	std::cout << "But since it is empty there is no content to access :\n";
	try {
		std::cout << arrayEmpty[0] << std::endl;
	}
	catch (const std::out_of_range& e) {
		std::cout << "Empty array [0] is not accessible because [";
		std::cout << e.what() << "]" << std::endl;
	}


	std::cout << std::endl << "INTEGER ARRAY TEST" << std::endl;
	std::cout << "Let's initialize an int array of length " << ARRAY_LEN;
	std::cout << std::endl;
	Array	<int>arrayOfInt(ARRAY_LEN);

	std::cout << "We can check its size : " << arrayOfInt.size() << std::endl;

	std::cout << "We can access its content using the [ ] operator";
	std::cout << " such as : " << std::endl;
	for (int i = 0; i < ARRAY_LEN; i++) {
		std::cout << "[" << i << "] : " << arrayOfInt[i] << "\n";
	}

	std::cout << "Or modify the content of the array : " << std::endl;
	for (int i = 0; i < ARRAY_LEN; i++) {
		arrayOfInt[i] += i;
		std::cout << "[" << i << "] : " << arrayOfInt[i] << "\n";
	}

	std::cout << "But we cannot access an index higher than the array size :";
	std::cout << std::endl;
	try {
		std::cout << arrayOfInt[ARRAY_LEN] << std::endl;
	}
	catch (const std::out_of_range& e) {
		std::cout << "Array [" << ARRAY_LEN << "] is not accessible because [";
		std::cout << e.what() << "]" << std::endl;
	}

	std::cout << std::endl << "FLOAT ARRAY TEST" << std::endl;
	std::cout << "Let's initialize an float array of length " << ARRAY_LEN;
	std::cout << std::endl;
	Array	<float>arrayOfFloat(ARRAY_LEN);

	std::cout << "We can check its size : " << arrayOfFloat.size() << std::endl;

	std::cout << "We can access its content using the [ ] operator";
	std::cout << " such as : " << std::endl;
	for (int i = 0; i < ARRAY_LEN; i++) {
		std::cout << "[" << i << "] : " << arrayOfFloat[i] << "\n";
	}

	std::cout << "Or modify the content of the array : " << std::endl;
	for (int i = 0; i < ARRAY_LEN; i++) {
		arrayOfFloat[i] += i + 0.5;
		std::cout << "[" << i << "] : " << arrayOfFloat[i] << "\n";
	}

	std::cout << std::endl << "STRING ARRAY TEST" << std::endl;
	std::cout << "Let's initialize an string array of length " << ARRAY_LEN;
	std::cout << std::endl;
	Array	<std::string>arrayOfString(ARRAY_LEN);

	std::cout << "We can check its size : " << arrayOfString.size() << std::endl;

	std::cout << "We can access its content using the [ ] operator";
	std::cout << " such as : " << std::endl;
	for (int i = 0; i < ARRAY_LEN; i++) {
		std::cout << "[" << i << "] : \"" << arrayOfString[i] << "\"\n";
	}

	std::cout << "Or modify the content of the array : " << std::endl;
	for (int i = 0; i < ARRAY_LEN; i++) {
		std::stringstream	content;
		content << "Hello, I am string number " << i;
		arrayOfString[i] = content.str();
		std::cout << "[" << i << "] : \"" << arrayOfString[i] << "\"\n";
	}

	std::cout << std::endl << "BONUS" << std::endl;
	std::cout << "If you're curious, here is the tip suggested";
	std::cout << " in the subject:" << std::endl;
	{
		int*	a = new int();
		std::cout << "int*	a = new int(); displays [" << *a << "]\n";
		delete a;
	}



	// std::cout << "And even combine these template based functions ";
	// std::cout << "by first incrementing and then printing." << std::endl;
	// iter(arrayOfInt, arrayLen, incrementAnyElem<int>);
	// iter(arrayOfInt, arrayLen, printAnyElem<int>);









	return (0);
}
