#include <iostream>
#include <vector>
#include <stdlib.h>
#include "Span.hpp"

void	testEmptySpan(int size)
{
	std::cout << "EMPTY SPAN:\n";

	Span spam = Span(size);
	std::cout << "I create an empty Span with a maximal size of " << size;
	std::cout << " and a current size of " << spam.getSize() << ".\n";

	try {
		spam.shortestSpan();
		std::cout << "If this works there is a problem !!";
	}
	catch (const std::logic_error& e) {
		std::cout << "As expected, trying to get the shortspan of an empty span";
		std::cout << " throws :\n[" << e.what() << "]\n";
	}
}

void	testAddingRange(int size)
{
	std::cout << "\nADDING A RANGE\n";

	Span spam = Span(size);
	std::cout << "I create an empty Span with a maximal size of " << size;
	std::cout << " and a current size of " << spam.getSize() << ".\n";

	std::cout << "Then I create a vector and fill it with ";
	std::cout << size - 1 << " elements.\n";
	std::vector<int>	vectorToAdd;
	for (int i = 0; i < size; i++) {
		vectorToAdd.push_back(i);
	}
	#ifdef PRINT
	printContainer(vectorToAdd);
	#endif

	std::cout << "We can add the content of that vector to the span.\n";
	spam.addRange(vectorToAdd.begin(), vectorToAdd.end());
	#ifdef PRINT
	std::cout << "and then print the content of the Span: \n";
	spam.printSpan();
	#endif
	std::cout << "The span is now of size " << spam.getSize() << std::endl;

	std::cout << "I can still find the shortest and longest spans :\n";
	std::cout << "shortest span: " << spam.shortestSpan() << std::endl;
	std::cout << "longest span: " << spam.longestSpan() << std::endl;
}

void	testAddingPastSize(int size)
{
	std::cout << "\nADDING PAST THE DETERMINED SIZE\n";

	Span spam = Span(size);
	std::cout << "I create an empty Span with a maximal size of " << size;
	for (int i = 0; i < size - 1; i++) {
		spam.addNumber(i);
	}
	std::cout << " and fill it to " << spam.getSize() << ".\n";

	std::vector<int>	vectorToAdd;
	for (int i = 0; i < 3; i++) {
		vectorToAdd.push_back(i);
	}
	std::cout << "Then I create a vector filled with " << vectorToAdd.size();

	try {
		spam.addRange(vectorToAdd.begin(), vectorToAdd.end());
		std::cout << "If this work, there is a problem !!\n";
	}
	catch (const std::logic_error& e) {
		std::cout << "\nTrying to add this vector, with more numbers than the";
		std::cout << " leftover space throws : \n[" << e.what() << "]\n";
	}

	std::cout << "I fill up my Span content by adding one more number\n";
	spam.addNumber(42);

	std::cout << "Since it reached its maximum size, I cannot add anymore\n";
	try {
		spam.addNumber(43);
		std::cout << "If this work, there is a problem !!\n";
	}
	catch (const std::logic_error& e) {
		std::cout << "Trying to add yet another number ";
		std::cout << "throws this error: \n[" << e.what() << "]\n";
	}
}

void	testRandomValueSpan(int size)
{
	std::cout << "\nRANDOM VALUES\n";

	srand (time(NULL));
	Span spam = Span(size);
	std::cout << "I create a Span with a maximal size of " << size;
	std::cout << " and fill it with random integers\n";
	for (int i = 0; i < size - 1; i++) {
		int random = rand();
		#ifdef PRINT
		std::cout << "added " << random << "\n";
		#endif
		spam.addNumber(random);
	}
	#ifdef PRINT
	spam.printSpan();
	#endif

	std::cout << "I can still find the shortest and longest spans\n";
	std::cout << "shortest span: " << spam.shortestSpan() << std::endl;
	std::cout << "longest span: " << spam.longestSpan() << std::endl;
}

int	main()
{
	std::cout << "Subject mandated test:\n\n";
	{
		Span	sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	std::cout << "\nHome made tests:\n\n";
	{
		int size = 100;

		testEmptySpan(size);
		testAddingRange(size);
		testAddingPastSize(size);
		testRandomValueSpan(size);
	}

	return (0);
}
