#include "Brain.hpp"

//----------------- CONSTRUCTORS ---------------------//

Brain::Brain()
{
	std::cout << "Calling Brain constructor" << std::endl;
}

//----------------- DESTRUCTOR -----------------------//
Brain::~Brain()
{
	std::cout << "Calling Brain destructor" << std::endl;
}

//----------------- COPY CONSTRUCTORS ----------------//
Brain::Brain( const Brain& original )
{
	std::cout << "Calling Brain copy constructor" << std::endl;
	*this = original;
}

//----------------- COPY ASSIGNEMENT -----------------//
Brain&			Brain::operator=( const Brain& original )
{
	std::cout << "Calling Brain copy assignment" << std::endl;

	if (this == &original)
		return *this;

	for (int i = 0; i < 100; i++)
		this->ideas[i] = original.ideas[i];

	return *this;
}
