#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
	{
		ClapTrap	CL4P("CL4P");

		CL4P.attack("Bob");

		CL4P.beRepaired(1);

		CL4P.takeDamage(11);

		CL4P.beRepaired(1);
	}

	{
		ScavTrap	Stakanov("Stakanov");

		Stakanov.guardGate();

		for (int i = 0; i < 11; i++) {
			Stakanov.attack("Bob");
		}

		for (int i = 0; i < 11; i++) {
			Stakanov.takeDamage(1);
		}

		Stakanov.guardGate();
	}

}
