#include "WrongCat.hpp"

//----------------- CONSTRUCTORS ---------------------//

WrongCat::WrongCat()
	: WrongAnimal()
{
	std::cout << "Calling WrongCat constructor for " << type << std::endl;
}

//----------------- DESTRUCTOR -----------------------//
WrongCat::~WrongCat()
{
	std::cout << "Calling WrongCat destructor for " << type << std::endl;
}

//----------------- COPY CONSTRUCTORS ----------------//
WrongCat::WrongCat( const WrongCat& original )
	: WrongAnimal()
{
	std::cout << "Calling WrongCat copy constructor for " << type << std::endl;
	*this = original;
}

//----------------- COPY ASSIGNEMENT -----------------//
WrongCat&			WrongCat::operator=( const WrongCat& original )
{
	std::cout << "Calling WrongCat copy assignment for " << type << std::endl;

	WrongAnimal::operator=(original);
	return *this;
}

//----------------- MEMBER FUNCTIONS -----------------//
void			WrongCat::makeSound() const
{
	std::cout << "🛎️  Riiiiinnng !!! " << std::endl;
}

std::string		WrongCat::getType() const
{
	return (type);
}
