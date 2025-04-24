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

}
