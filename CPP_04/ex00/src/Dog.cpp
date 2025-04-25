#include "Dog.hpp"

//----------------- CONSTRUCTORS ---------------------//

Dog::Dog()
	: Animal()
{
	std::cout << "Calling Dog constructor for " << type << std::endl;
	setType("Dog");
}

//----------------- DESTRUCTOR -----------------------//
Dog::~Dog()
{
	std::cout << "Calling Dog destructor for " << type << std::endl;
}

//----------------- COPY CONSTRUCTORS ----------------//
Dog::Dog( const Dog& original )
	: Animal()
{
	std::cout << "Calling Dog copy constructor for " << type << std::endl;
	setType("Dog");
}

//----------------- COPY ASSIGNEMENT -----------------//
Dog&			Dog::operator=( const Dog& original )
{
	std::cout << "Calling Dog copy assignment for " << type << std::endl;
	if (this != &original) {
		type = original.getType();
	}
	return *this;
}

//----------------- MEMBER FUNCTIONS -----------------//
void			Dog::makeSound() const
{
	std::cout << "🐕 Wooffff! " << std::endl;
}

std::string		Dog::getType() const
{
	return (type);
}
