#ifndef DIAMOND_CLASS_H
# define DIAMOND_CLASS_H

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap {

public:

	//----------------- CONSTRUCTORS ---------------------//
					DiamondTrap( std::string name);

	//----------------- DESTRUCTOR -----------------------//
					~DiamondTrap();

	//----------------- COPY CONSTRUCTORS ----------------//
					DiamondTrap( const DiamondTrap& original );

	//----------------- COPY ASSIGNEMENT -----------------//
	DiamondTrap&	operator=( const DiamondTrap& original );

	//----------------- MEMBER FUNCTIONS -----------------//
	void			whoAmI();

	// ---------------- INHERITED ------------------------//
	// void			attack( const std::string& target );
	// void			takeDamage( unsigned int amount );
	// void			beRepaired( unsigned int amount );

	void			resetHitPoint();
	void			resetEnergyPoint();
	void			resetAttackDamage();

private:

	std::string		_name;

};

#endif



