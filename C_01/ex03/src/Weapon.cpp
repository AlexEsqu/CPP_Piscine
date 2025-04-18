#include "Weapon.hpp"

Weapon::Weapon( std::string name ): _type(name) {
	std::cout << GREEN << "Creating weapon " << _type << STOP_COLOR << std::endl;
}

Weapon::~Weapon( void ) {
	std::cout << RED << "Destroying weapon " << _type << STOP_COLOR << std::endl;
}

const std::string&	Weapon::getType( void ) const {
	return (_type);
}

void				Weapon::setType( std::string type ) {
	std::cout << "Changing weapon type from " << _type;
	_type = type;
	std::cout << " to " << _type << std::endl;
}
