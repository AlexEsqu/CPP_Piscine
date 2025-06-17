#include <iostream>
#include <list>
#include <string>
#include "MutantStack.hpp"

void	testMutantStackInt()
{
	std::cout << "\nITERATING ON MUTANT STACK FILLED WITH INT\n" << std::endl;

	MutantStack<int> mstack;
	for (unsigned long i = 0; i < 10; i++) {
		mstack.push(i);
	}

	std::cout << "The start of the Mutant Stack is ";
	MutantStack<int>::iterator it = mstack.begin();
	std::cout << *it << std::endl;
	MutantStack<int>::iterator ite = mstack.end();
	// end iterator should not be dereferenced (undefined behaviour), but
	// only used to check if the end of the container is reached

	std::cout << "It can be used to iterate over the stack :\n";
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

void	testMutantStackString()
{
	std::cout << "\nITERATING ON MUTANT STACK FILLED WITH STRING\n" << std::endl;

	MutantStack<std::string> mstack;
	mstack.push("Adieu");
	mstack.push("Goodbye");
	mstack.push("Auf Wiedersehen");
	mstack.push("Den letzten weg musst du allein gehen");
	mstack.push("Ein letztes Lied, ein letzter Kuss");
	mstack.push("Kein Wunder wird gescheh'n");


	std::cout << "The start of the Mutant Stack is \"";
	MutantStack<std::string>::iterator it = mstack.begin();
	std::cout << *it << "\"\n";
	MutantStack<std::string>::iterator ite = mstack.end();
	// end iterator should not be dereferenced (undefined behaviour), but
	// only used to check if the end of the container is reached

	std::cout << "It can be used to iterate over the stack :\n";
	while (it != ite)
	{
		std::cout << "\"" << *it << "\"\n";
		++it;
	}
}

void	testMutantStackIncrement()
{
	std::cout << "\nINCREMENTING MUTANT STACK ITERATOR\n" << std::endl;

	MutantStack<int> mstack;
	for (unsigned long i = 0; i < 10; i++) {
		mstack.push(i);
	}

	std::cout << "In our Mutant Stack, iterator can be incremented:\n";
	MutantStack<int>::iterator start = mstack.begin();
	std::cout << "The start of the stack is " << *start;
	std::cout << "\nstart++ returns " << *start++;
	std::cout << " but the iterator is now at " << *start;
	std::cout << "\nstart-- returns " << *start--;
	std::cout << " but the iterator is now at " << *start;

	std::cout << "\nwhile --start returns " << --*start;
	std::cout << " and stays at " << *start;
	std::cout << "\nand ++start returns " << ++*start;
	std::cout << " and stays at " << *start << "\n";

	std::cout << "\nMeanwhile a list iterator does:\n";

	std::list<int> mlist;
	for (unsigned long i = 0; i < 10; i++) {
		mlist.push_back(i);
	}
	std::list<int>::iterator liststart = mlist.begin();
	std::cout << "The start of the list is " << *liststart;
	std::cout << "\nstart++ returns " << *liststart++;
	std::cout << " but the iterator is now at " << *liststart;
	std::cout << "\nstart-- returns " << *liststart--;
	std::cout << " but the iterator is now at " << *liststart;

	std::cout << "\nwhile --start returns " << --*liststart;
	std::cout << " and stays at " << *liststart;
	std::cout << "\nand ++start returns " << ++*liststart;
	std::cout << " and stays at " << *liststart << "\n";

}

void	subjectMandatedTest()
{
	std::cout << "Here is the code snippet for our Mutant Stack:\n";

	{
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << std::endl;

		mstack.pop();

		std::cout << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
		std::stack<int> s(mstack);
	}

	std::cout << "Here is the code snippet adapted for a list:\n";

	{
		std::list<int> mlist;

		// using push_back() instead of push() as per subject suggestion
		mlist.push_back(5);
		mlist.push_back(17);

		// accessing the first element with back() instead of top()
		std::cout << mlist.back() << std::endl;

		// removing the first element with pop_back() instead of pop()
		mlist.pop_back();

		std::cout << mlist.size() << std::endl;

		mlist.push_back(3);
		mlist.push_back(5);
		mlist.push_back(737);
		//[...]
		mlist.push_back(0);

		std::list<int>::iterator it = mlist.begin();
		std::list<int>::iterator ite = mlist.end();

		++it;
		--it;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
		std::list<int> s(mlist);
	}


}


int	main()
{
	std::cout << "---- Subject mandated test ----\n\n";

	subjectMandatedTest();

	std::cout << "\n---- Home made tests ----\n";

	testMutantStackInt();
	testMutantStackString();
	testMutantStackIncrement();

	return (0);
}
