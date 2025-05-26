#include <iostream>
#include <list>
#include <string>
#include "MutantStack.hpp"

int main()
{

	std::cout << "For reference, with a LIST :" << std::endl;
	{
		std::list<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << mstack.back() << std::endl;
		mstack.pop_back();
		std::cout << mstack.size() << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		//[...]
		mstack.push_back(0);

		std::list<int>::iterator it = mstack.begin();
		std::cout << "The start of the list is " << *it << std::endl;
		std::list<int>::iterator ite = mstack.end();
		std::cout << "The end of the list is " << *ite << std::endl;
		++it;
		std::cout << "The start of the list ++ is " << *it << std::endl;
		--it;
		std::cout << "The start of the list -- is " << *it << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::list<int> s(mstack);
	}

	std::cout << std::endl << "And with our MUTANT :" << std::endl;
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
		std::cout << "The start of the Mutant Stack is " << *it << std::endl;
		MutantStack<int>::iterator ite = mstack.end();
		std::cout << "The end of the Mutant Stack is " << *ite << std::endl;
		++it;
		std::cout << "The start of the Mutant Stack ++ is " << *it << std::endl;
		--it;
		std::cout << "The start of the Mutant Stack -- is " << *it << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}

	std::cout << std::endl << "And even with strings in our MUTANT :" << std::endl;
	{
		MutantStack<std::string> mstack;
		mstack.push("Adieu");
		mstack.push("Goodbye");
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push("Auf Wiedersehen");
		mstack.push("Den letzten weg musst du allein gehen");
		mstack.push("Ein letztes Lied, ein letzter Kuss");
		//[...]
		mstack.push("Kein Wunder wird gescheh'n");
		MutantStack<std::string>::iterator it = mstack.begin();
		std::cout << "The start of the Mutant Stack is " << *it << std::endl;
		MutantStack<std::string>::iterator ite = mstack.end();
		std::cout << "The end of the Mutant Stack is " << *ite << std::endl;
		++it;
		std::cout << "The start of the Mutant Stack ++ is " << *it << std::endl;
		--it;
		std::cout << "The start of the Mutant Stack -- is " << *it << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<std::string> s(mstack);
	}


	return 0;
}
