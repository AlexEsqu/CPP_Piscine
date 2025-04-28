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
	virtual			~ClapTrap();

	//----------------- COPY CONSTRUCTORS ----------------//
					ClapTrap( const ClapTrap& original );

	//----------------- COPY ASSIGNEMENT -----------------//
	ClapTrap&		operator=( const ClapTrap& original );

	//----------------- MEMBER FUNCTIONS -----------------//
	virtual void	attack( const std::string& target );
	void			takeDamage( unsigned int amount );
	void			beRepaired( unsigned int amount );

	std::string		getName() const ;

	int				getHitPoint() const ;
	int				getEnergyPoint() const ;
	int				getAttackDamage() const ;

	void			setHitPoint( int new_hit_point );
	void			setEnergyPoint( int new_energy_point );
	void			setAttackDamage( int new_attack_damage );

	virtual void	resetHitPoint();
	virtual void	resetEnergyPoint();
	virtual void	resetAttackDamage();

	void			displayStats();


private:

	std::string		_name;
	int				_hit_point;
	int				_energy_point;
	int				_attack_damage;

};

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define STOP_COLOR "\033[0m"

# define FAINT "\033[2m"
# define BOLD "\033[1m"
# define STOP_STYLE "\033[22m"

# define ITALIC "\033[3m"
# define STOP_ITALIC "\033[23m"


#endif
