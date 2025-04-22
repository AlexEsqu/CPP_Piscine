#ifndef CLAPTRAP_CLASS_H
# define CLAPTRAP_CLASS_H

# include <string>
# include <iostream>

class ClapTrap {

public:

	//----------------- CONSTRUCTORS ---------------------//
					ClapTrap();
					ClapTrap( std::string name);

	//----------------- DESTRUCTOR -----------------------//
					~ClapTrap();

	//----------------- COPY CONSTRUCTORS ----------------//
					ClapTrap( const ClapTrap& original );

	//----------------- COPY ASSIGNEMENT -----------------//
	ClapTrap&		operator=( const ClapTrap& original );

	//----------------- MEMBER FUNCTIONS -----------------//
	void			attack( const std::string& target );
	void			takeDamage( unsigned int amount );
	void			beRepaired( unsigned int amount );

private:

	std::string		_name;
	int				_hit_point;
	int				_energy_point;
	int				_attack_damage;

};



#endif
