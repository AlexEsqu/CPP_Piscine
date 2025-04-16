#include "Zombie.hpp"

// Generic Constructor
Zombie::Zombie( void ) {
	std::cout << "Generic Zombie rose from the grave..." << std::endl;
}

// Named Constructor, assigns name to the Zombie's _name variable
Zombie::Zombie( std::string name ): _name(name) {
	std::cout << "Zombie " << _name << " rose from the grave..." << std::endl;
}

// Generic Destructor
Zombie::~Zombie( void ) {
	std::cout << "Zombie " << _name << " was slain." << std::endl;
}

// Prints name and scream of a Zombie
void	Zombie::announce( void ) const {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setZombieName( std::string name ) {
	_name = name;
}
