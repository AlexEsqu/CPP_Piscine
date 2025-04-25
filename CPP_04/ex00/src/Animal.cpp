#include "Animal.hpp"

//----------------- CONSTRUCTORS ---------------------//

Animal::Animal()
	: type("meta-animal")
{
	std::cout << "Calling Animal constructor for " << type << std::endl;
}

//----------------- DESTRUCTOR -----------------------//
Animal::~Animal()
{
	std::cout << "Calling Animal destructor for " << type << std::endl;
}

//----------------- COPY CONSTRUCTORS ----------------//
Animal::Animal( const Animal& original )
	: type(original.getType())
{
	std::cout << "Calling Animal copy constructor for " << type << std::endl;
}

//----------------- COPY ASSIGNEMENT -----------------//
Animal&			Animal::operator=( const Animal& original )
{
	std::cout << "Calling Animal copy assignment for " << type << std::endl;
	if (this != &original) {
		type = original.getType();
	}
	return *this;
}

//----------------- MEMBER FUNCTIONS -----------------//
void			Animal::makeSound() const
{
	std::cout << "🐅 rawr !" << std::endl;
}

std::string		Animal::getType() const
{
	return (type);
}

void			Animal::setType( std::string new_type )
{
	type = new_type;
}
