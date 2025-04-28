#ifndef SCAVTRAP_CLASS_H
# define SCAVTRAP_CLASS_H

#include "ClapTrap.hpp"

# define SCAVTRAP_HITPOINT 100
# define SCAVTRAP_ENERGY 50
# define SCAVTRAP_ATTACK 20

class ScavTrap: virtual public ClapTrap {

	public:

	//----------------- CONSTRUCTORS ---------------------//
					ScavTrap( std::string name);

	//----------------- DESTRUCTOR -----------------------//
					~ScavTrap();

	//----------------- COPY CONSTRUCTORS ----------------//
					ScavTrap( const ScavTrap& original );

	//----------------- COPY ASSIGNEMENT -----------------//
	ScavTrap&		operator=( const ScavTrap& original );

	//----------------- MEMBER FUNCTIONS -----------------//
	void			guardGate();

	// ---------------- INHERITED ------------------------//
	void			attack( const std::string& target );
	// void			takeDamage( unsigned int amount );
	// void			beRepaired( unsigned int amount );

	void			resetHitPoint();
	void			resetEnergyPoint();
	void			resetAttackDamage();

	private:


};

#endif



