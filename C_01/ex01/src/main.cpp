#include <iostream>
#include "Zombie.hpp"

#define HORDE_AMOUNT 5

int	main( void )
{
	std::cout << std::endl << "Welcome to the Zombie testing ground !!" << std::endl << std::endl;
	std::cout << "~~ ROUND 2 : Mass Heap allocation ~~" << std::endl << std::endl;


	std::cout << "Any good neC++mancer should be able to raise multiple Zombies at once..." << std::endl;
	Zombie* ZombieHorde = zombieHorde(HORDE_AMOUNT, "Minion");
	std::cout << std::endl;


	std::cout << "Able to make use of them..." << std::endl;
	for (int i = 0; i < HORDE_AMOUNT; i++) {
		ZombieHorde[i].announce();
	}
	std::cout << std::endl;


	std::cout << "And, of course, able to send them back to the grave !" << std::endl;
	delete[] ZombieHorde;

	return (0);
}
