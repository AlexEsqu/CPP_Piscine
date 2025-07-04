#include "Pair.hpp"

// ****************************************************************************#
//		PAIR																   #
// ****************************************************************************#

//----------------- PAIR CLASS -----------------//

Pair::Pair(int a, int b)
	: big(a)
	, small(b)
	, straggler(false)
{
	#ifdef PRINT
	//std::cout << "Calling Pair constructor" << std::endl;
	#endif
}

Pair::Pair(int a)
	: big(__INT16_MAX__)
	, small(a)
	, straggler(true)
{
	#ifdef PRINT
	//std::cout << "Calling Pair constructor" << std::endl;
	#endif
}

//----------------- DESTRUCTOR -----------------------//
Pair::~Pair()
{
	#ifdef PRINT
	//std::cout << "Calling Pair destructor" << std::endl;
	#endif
}

//----------------- COPY CONSTRUCTORS ----------------//
Pair::Pair( const Pair& original )
{
	#ifdef PRINT
	//std::cout << "Calling Pair copy constructor" << std::endl;
	#endif

	*this = original;
}

//----------------- COPY ASSIGNEMENT -----------------//
Pair&		Pair::operator=( const Pair& original )
{
	#ifdef PRINT
	//std::cout << "Calling Pair copy assignment" << std::endl;
	#endif

	if (this != &original) {
		big = original.getBig();
		small = original.getSmall();
		straggler = original.isStraggler();
	}

	return (*this);
}

// ****************************************************************************#
//		COMPARISON OPERATORS												   #
// ****************************************************************************#

bool 		Pair::operator==(const Pair& comp) const
{
	return (big == comp.big && small == comp.small && straggler == comp.straggler);
}

bool		Pair::operator>(const Pair& comp) const
{
	return (big > comp.big);
}

bool		Pair::operator>=(const Pair& comp) const
{
	return (*this > comp || *this == comp);
}

bool		Pair::operator<(const Pair& comp) const
{
	return (big < comp.big);
}

bool		Pair::operator<=(const Pair& comp) const
{
	return (*this < comp || *this == comp);
}

// ****************************************************************************#
//		REPRESENTATION														   #
// ****************************************************************************#

std::ostream& operator<< (std::ostream& stream, const Pair& pair)
{
	if (pair.isStraggler())
		stream << "<Straggler: ["<< pair.getSmall() << "]>";
	else
	{
		stream << "<Big: [" << pair.getBig();
		stream << "] Small [" << pair.getSmall() << "]>";
	}
	return (stream);
}

// ****************************************************************************#
//		GETTERS																   #
// ****************************************************************************#

int Pair::getBig() const
{
	return (big);
}

int Pair::getSmall() const
{
	return (small);
}

bool Pair::isStraggler() const
{
	return (straggler);
}
