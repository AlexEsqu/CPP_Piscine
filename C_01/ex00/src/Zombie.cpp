#include "Zombie.hpp"

// Generic Constructor, assigns name to the Zombie's _name variable
Zombie::Zombie( std::string name ): _name(name) { }

// Generic Destructor
Zombie::~Zombie( void ) { }

// Prints name and scream of a Zombie
void	Zombie::announce( void ) const
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
