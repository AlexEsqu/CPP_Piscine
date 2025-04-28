#include "A_Materia.hpp"

//----------------- CONSTRUCTORS ---------------------//

AMateria::AMateria(const std::string& type)
	: _type(type)
{
	if (DEBUG)
		std::cout << GREEN << "[MATERIA] Constructor" << STOP_COLOR << std::endl;
}

//----------------- DESTRUCTOR -----------------------//

AMateria::~AMateria()
{
	if (DEBUG)
		std::cout << RED << "[MATERIA] Destructor" << STOP_COLOR << std::endl;
}

//----------------- COPY CONSTRUCTORS ----------------//

AMateria::AMateria( const AMateria& original )
	: _type(original.getType())
{
	if (DEBUG)
		std::cout << GREEN << "[MATERIA] Copy Constructor" << STOP_COLOR << std::endl;
}

//----------------- COPY ASSIGNMENT ------------------//

AMateria&			AMateria::operator=( const AMateria& original )
{
	if (DEBUG)
		std::cout << GREEN << "[MATERIA] Copy Assignment" << STOP_COLOR << std::endl;

	if (this == &original)
		return *this;

	_type = original.getType();
	return *this;
}

//----------------- MEMBER FUNCTIONS -----------------//

const std::string&	AMateria::getType() const
{
	return (_type);
}

void				AMateria::use(ICharacter& target)
{
	std::cout << MAGENTA << "Using a mystery Materia on ";
	std::cout << target.getName() << STOP_COLOR << std::endl;
}
