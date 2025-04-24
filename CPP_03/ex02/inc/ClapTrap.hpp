#ifndef CLAPTRAP_CLASS_H
# define CLAPTRAP_CLASS_H

# include <string>
# include <iostream>

# define CLAPTRAP_HITPOINT 10
# define CLAPTRAP_ENERGY 10
# define CLAPTRAP_ATTACK 0

class ClapTrap {

public:

	//----------------- CONSTRUCTORS ---------------------//
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

	std::string		getName() const ;

	int				getHitPoint() const ;
	int				getEnergyPoint() const ;
	int				getAttackDamage() const ;

	void			setHitPoint( int new_hit_point );
	void			setEnergyPoint( int new_energy_point );
	void			setAttackDamage( int new_attack_damage );

	void			resetHitPoint();
	void			resetEnergyPoint();
	void			resetAttackDamage();

	void			displayStats();


private:

	std::string		_name;
	int				_hit_point;
	int				_energy_point;
	int				_attack_damage;

};



#endif
