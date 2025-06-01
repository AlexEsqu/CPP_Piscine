#include "FragTrap.hpp"

//----------------- CONSTRUCTORS ---------------------//

FragTrap::FragTrap( std::string name)
	: ClapTrap(name)
{
	std::cout << GREEN << FAINT << "FragTrap constructor called for ";
	std::cout << name;
	std::cout << STOP_COLOR << STOP_STYLE << std::endl;

	setHitPoint(100);
	setEnergyPoint(100);
	setAttackDamage(30);
}

//----------------- DESTRUCTOR -----------------------//

FragTrap::~FragTrap()
{
	std::cout << RED << FAINT << "FragTrap destructor called";
	std::cout << STOP_COLOR << STOP_STYLE << std::endl;
}

//----------------- COPY CONSTRUCTORS ----------------//

FragTrap::FragTrap( const FragTrap& original )
	: ClapTrap(original)
{
	std::cout << GREEN << FAINT << "FragTrap copy constructor called";
	std::cout << STOP_COLOR << STOP_STYLE << std::endl;

	setHitPoint(original.getHitPoint());
	setEnergyPoint(original.getEnergyPoint());
	setAttackDamage(original.getAttackDamage());

}

//----------------- COPY ASSIGNEMENT -----------------//

FragTrap&	FragTrap::operator=( const FragTrap& original )
{
	std::cout << GREEN << FAINT << "FragTrap copy assignement called";
	std::cout << STOP_COLOR << STOP_STYLE << std::endl;

	ClapTrap::operator=(original);
	return *this;
}

//----------------- MEMBER FUNCTIONS -----------------//

void		FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << getName() << " is requesting a high five !" << std::endl;
}

void		FragTrap::resetHitPoint()
{
	setHitPoint(FRAGTRAP_HITPOINT);
}

void		FragTrap::resetEnergyPoint()
{
	setEnergyPoint(FRAGTRAP_ENERGY);
}

void		FragTrap::resetAttackDamage()
{
	setAttackDamage(FRAGTRAP_ATTACK);
}
