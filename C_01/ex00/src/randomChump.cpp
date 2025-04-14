#include "Zombie.hpp"

// Creates, name and announce a stack allocated Zombie,
// Which is destroyed as soon as the function ends
void	Zombie::randomChump( std::string name )
{
	Zombie(name);
}
