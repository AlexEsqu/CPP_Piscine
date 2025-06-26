#include "Cure.hpp"

//----------------- CONSTRUCTORS ---------------------//

Cure::Cure()
	: AMateria("cure")
{
	if (DEBUG)
		std::cout << GREEN << "[CURE] Constructor" << STOP_COLOR << std::endl;
}

//----------------- DESTRUCTOR -----------------------//

Cure::~Cure()
{
	if (DEBUG)
		std::cout << RED << "[CURE] Destructor" << STOP_COLOR << std::endl;
}

//----------------- COPY CONSTRUCTORS ----------------//

Cure::Cure( const Cure& original )
	: AMateria(original.getType())
{
	if (DEBUG)
		std::cout << GREEN << "[CURE] Copy Constructor" << STOP_COLOR << std::endl;
}

//----------------- COPY ASSIGNEMENT -----------------//

Cure&				Cure::operator=( const Cure& original )
{
	if (DEBUG)
		std::cout << GREEN << "[CURE] Copy Assignement" << STOP_COLOR << std::endl;

	_type = original.getType();
	return *this;
}

//----------------- MEMBER FUNCTIONS -----------------//

Cure*				Cure::clone() const
{
	if (DEBUG)
		std::cout << GREEN << "[CURE] Cloning" << STOP_COLOR << std::endl;

	Cure	*pClone = new Cure();
	return (pClone);
}

const std::string&	Cure::getType() const
{
	return (_type);
}

void				Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
