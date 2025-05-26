#include <iostream>
#include <vector>
#include "Span.hpp"

int	main()
{
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

	{
		Span				spam = Span(100001);
		std::vector<int>	vectorToAdd;

		try { spam.shortestSpan(); }
		catch (const std::logic_error& e) {
			std::cout << "Trying to get the shortspan of an empty span throws : ";
			std::cout << e.what() << std::endl;
		}

		for (int i = -50; i <= (100000 - 50); i++) {
			vectorToAdd.push_back(i);
		}

		std::cout << "We can add the content of a vector to the span:" << std::endl;
		spam.addRange(vectorToAdd.begin(), vectorToAdd.end());
		std::cout << spam.shortestSpan() << std::endl;
		std::cout << spam.longestSpan() << std::endl;
		std::cout << "The span is now of size " << spam.getSize() << std::endl;

		std::cout << "Since this is its maximum size, it cannot accept anymore.";
		std::cout << std::endl;
		try { spam.addNumber(200); }
		catch (const std::logic_error& e) {
			std::cout << "Trying to add number throws this error: ";
			std::cout << e.what() << std::endl;
		}

		try { spam.addRange(vectorToAdd.begin(), vectorToAdd.end()); }
		catch (const std::logic_error& e) {
			std::cout << "Trying to add a range throws this error: ";
			std::cout << e.what() << std::endl;
		}

	}








	return (0);
}
