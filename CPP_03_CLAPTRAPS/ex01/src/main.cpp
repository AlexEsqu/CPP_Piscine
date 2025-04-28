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
		CL4P.takeDamage(1);
	}

	{
		ScavTrap	Stakanov("Stakanov");
		Stakanov.displayStats();
		Stakanov.guardGate();
		for (int i = 0; i < 11; i++) {
			Stakanov.attack("Bob");
		}
		for (int i = 0; i < 4; i++) {
			Stakanov.takeDamage(1);
		}
		Stakanov.guardGate();
		Stakanov.displayStats();
	}

	// Why does attack() need to be virtual ? Because it ensure overriding :
	{
		ScavTrap	Beep("Beep");
		ClapTrap* pTrap = &Beep;
		pTrap->displayStats();
		pTrap->attack("Bob");
	}

	// Why does destructor have to be virtual ? Same reason !
	{
		ClapTrap* pCock;
		pCock = new ScavTrap("Cockroach");
		pCock->displayStats();
		delete pCock;
	}

	// Testing the copy constructor
	{
		ScavTrap	Original("CopyCat");
		ScavTrap	Copy(Original);
		Copy.displayStats();
		Copy.attack("Bob");
	}

	// Testing the copy assignement
	{
		ScavTrap	Original("EqualsOrNothing");
		ScavTrap	Copy = Original;
		Copy.displayStats();
		Copy.attack("Bob");
	}

}
