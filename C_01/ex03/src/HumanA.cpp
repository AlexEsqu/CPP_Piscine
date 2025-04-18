#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon& weapon ): _name(name), _weapon(weapon) {
	std::cout << GREEN <<  "Creating human A " << _name << " armed with " << _weapon.getType() << STOP_COLOR << std::endl;
}

HumanA::~HumanA( void ) {
	std::cout << RED <<  "Destroying human A " << _name << STOP_COLOR << std::endl;
}

void	HumanA::attack( void ) const {
	std::cout << MAGENTA << _name << " attacks with " << _weapon.getType() << STOP_COLOR << std::endl;
}
