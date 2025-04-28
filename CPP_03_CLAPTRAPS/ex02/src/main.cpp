#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main()

{
	{
		ClapTrap	CL4P("CL4P");
		CL4P.displayStats();
		CL4P.attack("Bob");
		CL4P.beRepaired(1);
		CL4P.takeDamage(11);
		CL4P.beRepaired(1);
	}

	{
		ScavTrap	Stakanov("Stakanov");
		Stakanov.displayStats();
		Stakanov.guardGate();
		for (int i = 0; i < 5; i++) {
			Stakanov.attack("Bob");
		}
		Stakanov.displayStats();
	}

	{
		FragTrap	INAC("INAC");
		INAC.displayStats();
		INAC.highFivesGuys();
		INAC.attack("Bob");
		INAC.highFivesGuys();
		INAC.displayStats();
	}

	// Testing the copy constructor
	{
		FragTrap	Original("CopyCat");
		FragTrap	Copy(Original);
		Copy.displayStats();
		Copy.attack("Bob");
	}

	// Testing the copy assignement
	{
		FragTrap	Original("EqualsOrNothing");
		FragTrap	Copy = Original;
		Copy.displayStats();
		Copy.attack("Bob");
	}

}
