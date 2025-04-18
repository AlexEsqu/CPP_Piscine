#include "HumanB.hpp"

HumanB::HumanB( std::string name ): _name(name), _weapon(NULL) {
	std::cout << GREEN << "Creating human B " << _name << STOP_COLOR << std::endl;
}

HumanB::~HumanB( void ) {
	std::cout << RED << "Destroying human B " << _name << STOP_COLOR << std::endl;
}

void	HumanB::attack( void ) const {
	if (!_weapon)
		std::cout << MAGENTA << _name << " attacks with no weapon" << STOP_COLOR << std::endl;
	else
		std::cout << MAGENTA << _name << " attacks with " << _weapon->getType() << STOP_COLOR << std::endl;
}

void	HumanB::setWeapon( Weapon& weapon ) {
	_weapon = &weapon;
	std::cout << "Equiping human B " << _name << " with " << _weapon->getType() <<  std::endl;
};
