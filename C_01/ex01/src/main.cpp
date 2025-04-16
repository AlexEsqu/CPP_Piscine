#include <iostream>
#include "Zombie.hpp"

#define HORDE_AMOUNT 10

int	main( void )
{
	std::cout << "Welcome to the Zombie testing ground" << std::endl;
	std::cout << "~~ ROUND 2 : Mass Heap allocation ~~" << std::endl;

	std::cout << "Any good neC++mancer should be able to raise multiple Zombies at once..." << std::endl;
	Zombie* ZombieHorde = zombieHorde(HORDE_AMOUNT, "Minion");

	for (int i = 0; i < HORDE_AMOUNT; i++) {
		delete(ZombieHorde[i]);
	}

	return (0);
}
