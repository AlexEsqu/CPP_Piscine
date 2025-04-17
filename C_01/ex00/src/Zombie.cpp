#include "Zombie.hpp"

// Generic Constructor, assigns name to the Zombie's _name variable
Zombie::Zombie( std::string name ): _name(name) {
	std::cout << GREEN << "Zombie " << _name << " rose from the grave..." << STOP_COLOR << std::endl;
}

// Generic Destructor
Zombie::~Zombie( void ) {
	std::cout << RED << "Zombie " << _name << " was slain." << STOP_COLOR << std::endl;
}

// Prints name and scream of a Zombie
void	Zombie::announce( void ) const
{
	std::cout << FAINT << MAGENTA << _name << ": BraiiiiiiinnnzzzZ..." << STOP_COLOR << STOP_STYLE << std::endl;
}
