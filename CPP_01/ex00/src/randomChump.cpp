#include "Zombie.hpp"

// Creates, name and announce a stack allocated Zombie,
// Which is destroyed as soon as the function ends
void	randomChump( std::string name )
{
	Zombie rando(name);
	rando.announce();
}
