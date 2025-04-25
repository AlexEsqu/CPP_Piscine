#include "Cat.hpp"

//----------------- CONSTRUCTORS ---------------------//

Cat::Cat()
	: Animal()
{
	std::cout << "Calling Cat constructor for " << type << std::endl;
	setType("Cat");
}

//----------------- DESTRUCTOR -----------------------//
Cat::~Cat()
{
	std::cout << "Calling Cat destructor for " << type << std::endl;
}

//----------------- COPY CONSTRUCTORS ----------------//
Cat::Cat( const Cat& original )
	: Animal()
{
	std::cout << "Calling Cat copy constructor for " << type << std::endl;
	*this = original;
}

//----------------- COPY ASSIGNEMENT -----------------//
Cat&			Cat::operator=( const Cat& original )
{
	std::cout << "Calling Cat copy assignment for " << type << std::endl;

	Animal::operator=(original);
	return *this;
}

//----------------- MEMBER FUNCTIONS -----------------//
void			Cat::makeSound() const
{
	std::cout << "🐈 Mrrraw~~ " << std::endl;
}

std::string		Cat::getType() const
{
	return (type);
}
