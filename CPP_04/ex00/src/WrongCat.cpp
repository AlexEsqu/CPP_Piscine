#include "WrongCat.hpp"

//----------------- CONSTRUCTORS ---------------------//

WrongCat::WrongCat()
	: type("WrongCat")
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
{
	std::cout << "Calling WrongCat copy constructor for " << type << std::endl;
}

//----------------- COPY ASSIGNEMENT -----------------//
WrongCat&			WrongCat::operator=( const WrongCat& original )
{
	std::cout << "Calling WrongCat copy assignment for " << type << std::endl;
}

//----------------- MEMBER FUNCTIONS -----------------//
void			WrongCat::makeSound() const
{
	std::cout << "🛎️ Riiiiinnng !!! " << std::endl;
}

std::string		WrongCat::getType() const
{
	return (type);
}
