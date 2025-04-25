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

		// Why does attack() need to be virtual ? Because it ensure overriding :
		ClapTrap* pTrap = &Stakanov;
		pTrap->displayStats();
		pTrap->attack("BObo");

	}

	// Why does destructor have to be virtual ? Same reason !
	{
		ClapTrap* pCock;
		pCock = new ScavTrap("Cockroach");
		pCock->displayStats();
		delete pCock;
	}

}
