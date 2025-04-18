#ifndef HUMANA_CLASS_H
# define HUMANA_CLASS_H

# include "Weapon.hpp"

class HumanA
{

public:
				HumanA( std::string name, Weapon& Weapon );
				~HumanA( void );
	void		attack ( void ) const;

private:
	std::string	_name;
	Weapon&		_weapon;

};


#endif
