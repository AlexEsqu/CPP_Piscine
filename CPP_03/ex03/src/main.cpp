#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main()
{
	std::cout << "Testing the new DiamondTrap :" << std::endl;
	{
		DiamondTrap	Stakanov("Stakanov");
		Stakanov.displayStats();

		for (int i = 0; i < 3; i++) {
			Stakanov.attack("Bob");
		}

		Stakanov.displayStats();

		Stakanov.whoAmI();

	}
	std::cout << std::endl;

	ClapTrap*	array_CL4P[4];
	{
		array_CL4P[0] = new ClapTrap("Base");
		array_CL4P[1] = new ScavTrap("Scav");
		array_CL4P[2] = new FragTrap("Frag");
		array_CL4P[3] = new DiamondTrap("Diams");
	}

	{
		for (int i = 0; i < 4; i++) {
			array_CL4P[i]->displayStats();
			array_CL4P[i]->attack("Bob");
			std::cout << std::endl;
		}
	}

	{
		for (int i = 0; i < 4; i++) {
			delete array_CL4P[i];
			std::cout << std::endl;
		}
	}

}
