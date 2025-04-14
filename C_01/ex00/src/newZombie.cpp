#include "Zombie.hpp"

// Creates, name and return a heap allocated zombie
Zombie*	Zombie::newZombie( std::string name )
{
	Zombie*	Z_pointer;

	Zombie(name, Z_pointer);
	return (Z_pointer);
}
