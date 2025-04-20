#include <iostream>
#include "Zombie.hpp"

int	main( void )
{
	std::cout << std::endl << "Welcome to the Zombie testing ground !!" << std::endl << std::endl;
	std::cout << "~~ ROUND 1 : Stack vs Heap ~~" << std::endl << std::endl;

	std::cout << "- Calling forth a Zombie from the heap -" << std::endl;
	Zombie *Heap_Zombie = newZombie("Marco Raison Baronet of the Heap");
	std::cout << std::endl;

	std::cout << "- Calling forth a Zombie from the stack -" << std::endl;
	randomChump("Isa Cremant Priestess of the Stack");
	std::cout << std::endl;

	std::cout << "As you saw, Isa from the Stack rose, screamed and";
	std::cout << " died immediately after." << std::endl;
	std::cout << "After all, I don't need anything else from her." << std::endl;
	std::cout << std::endl;
	std::cout << "Meanwhile Marco from the Heap is still around." << std::endl;
	std::cout << "I can still hear his scream..." << std::endl;
	Heap_Zombie->announce();
	std::cout << std::endl;

	std::cout << "Since he resides in the Heap, though, I will need to slain him myself..." << std::endl;
	std::cout << "TAKE THAT !!!! " << BOLD << MAGENTA << "  delete (pointer_on_zombie)  " << STOP_STYLE << STOP_COLOR << std::endl;
	delete (Heap_Zombie);
	std::cout << "And now that all necromantic threat have been eradicated..." << std::endl;
	std::cout << "We can rest with a clear conscience and freed memory ;)" << std::endl;
	return (0);
}
