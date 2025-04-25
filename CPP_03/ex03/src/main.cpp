#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main()
{

	{
		DiamondTrap	Stakanov("Stakanov");
		Stakanov.displayStats();

		Stakanov.attack("Bob");

		for (int i = 0; i < 5; i++) {
			Stakanov.takeDamage(1);
		}

		Stakanov.displayStats();

		Stakanov.whoAmI();

	}

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
			array_CL4P[i]->attack("bob");
		}
	}

	{
		for (int i = 0; i < 4; i++) {
			delete array_CL4P[i];
		}
	}

}
