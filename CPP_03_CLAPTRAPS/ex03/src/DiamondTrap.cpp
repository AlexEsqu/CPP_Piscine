#include "DiamondTrap.hpp"

//----------------- CONSTRUCTORS ---------------------//

DiamondTrap::DiamondTrap( std::string name)
	: ClapTrap(name + "_clap_name")
	, ScavTrap(name)
	, FragTrap(name)
{
	std::cout << GREEN << FAINT << "DiamondTrap constructor called for ";
	std::cout << name << STOP_COLOR << STOP_STYLE << std::endl;
	_name = name;
	FragTrap::resetHitPoint();
	ScavTrap::resetEnergyPoint();
	FragTrap::resetAttackDamage();
}

//----------------- DESTRUCTOR -----------------------//

DiamondTrap::~DiamondTrap()
{
	std::cout << RED << FAINT << "DiamondTrap destructor called";
	std::cout << STOP_COLOR << STOP_STYLE << std::endl;
}

//----------------- COPY CONSTRUCTORS ----------------//

DiamondTrap::DiamondTrap( const DiamondTrap& original )
	: ClapTrap(original)
	, ScavTrap(original)
	, FragTrap(original)
{
	std::cout << GREEN << FAINT << "DiamondTrap copy constructor called";
	std::cout << STOP_COLOR << STOP_STYLE << std::endl;

	_name = original._name;
	setHitPoint(original.getHitPoint());
	setEnergyPoint(original.getEnergyPoint());
	setAttackDamage(original.getAttackDamage());
}

//----------------- COPY ASSIGNEMENT -----------------//

DiamondTrap&	DiamondTrap::operator=( const DiamondTrap& original )
{
	std::cout << GREEN << FAINT << "DiamondTrap copy assignement called";
	std::cout << STOP_COLOR << STOP_STYLE << std::endl;

	ClapTrap::operator=(original);
	return *this;
}

//----------------- MEMBER FUNCTIONS -----------------//


void		DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap is named " << getName() << " or ";
	std::cout  << _name << " for short" << std::endl;
}

void		DiamondTrap::resetHitPoint()
{
	FragTrap::resetHitPoint();
}

void		DiamondTrap::resetEnergyPoint()
{
	ScavTrap::resetEnergyPoint();

}

void		DiamondTrap::resetAttackDamage()
{
	FragTrap::resetAttackDamage();
}
