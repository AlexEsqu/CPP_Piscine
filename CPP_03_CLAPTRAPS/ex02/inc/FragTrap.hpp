#ifndef FRAGTRAP_CLASS_H
# define FRAGTRAP_CLASS_H

#include "ClapTrap.hpp"

# define FRAGTRAP_HITPOINT 100
# define FRAGTRAP_ENERGY 100
# define FRAGTRAP_ATTACK 30

class FragTrap: virtual public ClapTrap {

	public:

	//----------------- CONSTRUCTORS ---------------------//
					FragTrap( std::string name);

	//----------------- DESTRUCTOR -----------------------//
					~FragTrap();

	//----------------- COPY CONSTRUCTORS ----------------//
					FragTrap( const FragTrap& original );

	//----------------- COPY ASSIGNEMENT -----------------//
	FragTrap&		operator=( const FragTrap& original );

	//----------------- MEMBER FUNCTIONS -----------------//
	void			highFivesGuys();

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
