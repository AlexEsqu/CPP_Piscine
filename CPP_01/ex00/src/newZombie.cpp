#include "Zombie.hpp"

// Creates, name and return a heap allocated zombie
Zombie*	newZombie( std::string name )
{
	Zombie*	Z_pointer;

	Z_pointer = new Zombie(name);
	return (Z_pointer);
}
