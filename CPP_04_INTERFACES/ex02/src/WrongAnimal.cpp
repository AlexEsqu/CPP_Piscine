#include "WrongAnimal.hpp"

//----------------- CONSTRUCTORS ---------------------//

WrongAnimal::WrongAnimal()
	: type("meta-WrongAnimal")
{
	std::cout << "Calling WrongAnimal constructor for " << type << std::endl;
}

//----------------- DESTRUCTOR -----------------------//
WrongAnimal::~WrongAnimal()
{
	std::cout << "Calling WrongAnimal destructor for " << type << std::endl;
}

//----------------- COPY CONSTRUCTORS ----------------//
WrongAnimal::WrongAnimal( const WrongAnimal& original )
	: type(original.getType())
{
	std::cout << "Calling WrongAnimal copy constructor for " << type << std::endl;
}

//----------------- COPY ASSIGNEMENT -----------------//
WrongAnimal&	WrongAnimal::operator=( const WrongAnimal& original )
{
	std::cout << "Calling WrongAnimal copy assignment for " << type << std::endl;
	if (this == &original)
		return *this;

	type = original.getType();
	return *this;
}

//----------------- MEMBER FUNCTIONS -----------------//
void			WrongAnimal::makeSound() const
{
	std::cout << "🤖 Bip! Biiiiiip!" << std::endl;
}

std::string		WrongAnimal::getType() const
{
	return (type);
}

void			WrongAnimal::setType( std::string new_type )
{
	type = new_type;
}
