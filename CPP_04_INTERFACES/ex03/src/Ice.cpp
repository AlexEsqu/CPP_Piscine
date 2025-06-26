#include "Ice.hpp"

//----------------- CONSTRUCTORS ---------------------//

Ice::Ice()
	: AMateria("ice")
{
	if (DEBUG)
		std::cout << GREEN << "[ICE] Constructor" << STOP_COLOR << std::endl;
}

//----------------- DESTRUCTOR -----------------------//

Ice::~Ice()
{
	if (DEBUG)
		std::cout << RED << "[ICE] Destructor" << STOP_COLOR << std::endl;
}

//----------------- COPY CONSTRUCTORS ----------------//

Ice::Ice( const Ice& original )
	: AMateria(original.getType())
{
	if (DEBUG)
		std::cout << GREEN << "[ICE] Copy Constructor" << STOP_COLOR << std::endl;
}

//----------------- COPY ASSIGNEMENT -----------------//

Ice&				Ice::operator=( const Ice& original )
{
	if (DEBUG)
		std::cout << GREEN << "[ICE] Copy Assignement" << STOP_COLOR << std::endl;

	_type = original.getType();
	return *this;
}

//----------------- MEMBER FUNCTIONS -----------------//

Ice*				Ice::clone() const
{
	if (DEBUG)
		std::cout << GREEN << "[ICE] Cloning" << STOP_COLOR << std::endl;

	Ice	*pClone = new Ice();
	return (pClone);
}

const std::string&	Ice::getType() const
{
	return (_type);
}

void				Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt as " << target.getName();
	std::cout << " *" << std::endl;
}
