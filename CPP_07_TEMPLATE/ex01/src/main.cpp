#include <iostream>
#include <string>
#include "iter.hpp"

void	printInt(int num)
{
	std::cout << "Int is " << num << std::endl;
}

void	printFloat(float num)
{
	std::cout << "Float is " << num << std::endl;
}

void	printChar(char character)
{
	std::cout << "Char is " << character << std::endl;
}

int	main()
{
	std::cout << "INTEGER ARRAY TEST" << std::endl;
	std::cout << "Let's initialize an int array." << std::endl;
	int	arrayLen = 5;
	int	arrayOfInt[arrayLen] = {4, 3, 2, 1, 0};

	std::cout << "We can use the iter function with the array address,";
	std::cout << " length and a function designed for integers:" << std::endl;
	iter(arrayOfInt, arrayLen, printInt);

	std::cout << "But also another templete based function if we specify";
	std::cout << " the type: " << std::endl;
	iter(arrayOfInt, arrayLen, printAnyElem<int>);

	std::cout << "And even combine these template based functions ";
	std::cout << "by first incrementing and then printing." << std::endl;
	iter(arrayOfInt, arrayLen, incrementAnyElem<int>);
	iter(arrayOfInt, arrayLen, printAnyElem<int>);


	std::cout << "FLOAT ARRAY TEST" << std::endl;
	std::cout << "Let's initialize a float array." << std::endl;
	float	arrayOfFloat[arrayLen] = {4.0f, 3.5f, 2.3f, 1.0f, 0.4f};

	std::cout << std::endl << "We can use the iter function with the array address,";
	std::cout << " length and a function designed for integers:" << std::endl;
	iter(arrayOfFloat, arrayLen, printFloat);

	std::cout << "But also another templete based function if we specify";
	std::cout << " the type: " << std::endl;
	iter(arrayOfFloat, arrayLen, printAnyElem<float>);

	std::cout << "And even combine these template based functions ";
	std::cout << "by first incrementing and then printing." << std::endl;
	iter(arrayOfFloat, arrayLen, incrementAnyElem<float>);
	iter(arrayOfFloat, arrayLen, printAnyElem<float>);


	std::cout  << std::endl << "CHAR TEST" << std::endl;
	std::cout << "Let's initialize a string: ";
	std::string str = "Hello and goodbye";
	std::cout << str << std::endl;

	std::cout << "We can use the iter function with the array address,";
	std::cout << " length and a function designed for string:" << std::endl;
	iter(str, str.length(), printChar);

	std::cout << "But also another templete based function if we specify";
	std::cout << " the type: " << std::endl;
	iter(str, str.length(), printAnyElem<char>);

	std::cout << "And even combine these template based functions ";
	std::cout << "by first incrementing and then printing." << std::endl;
	iter(&str[0], str.length(), incrementAnyElem<char>);
	iter(str, str.length(), printAnyElem<char>);

	return 0;
}
