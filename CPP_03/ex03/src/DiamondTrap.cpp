#include "DiamondTrap.hpp"

//----------------- CONSTRUCTORS ---------------------//

DiamondTrap::DiamondTrap( std::string name)
	: ClapTrap(name + "_clap_name")
	, ScavTrap(name)
	, FragTrap(name)
{
	std::cout << "DiamondTrap constructor called for " << name << std::endl;
	_name = name;
	FragTrap::resetHitPoint();
	ScavTrap::resetEnergyPoint();
	FragTrap::resetAttackDamage();
}

//----------------- DESTRUCTOR -----------------------//

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

//----------------- COPY CONSTRUCTORS ----------------//

DiamondTrap::DiamondTrap( const DiamondTrap& original )
	: ClapTrap(original)
	, ScavTrap(original)
	, FragTrap(original)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

//----------------- COPY ASSIGNEMENT -----------------//

DiamondTrap&	DiamondTrap::operator=( const DiamondTrap& original )
{
	std::cout << "DiamondTrap copy assignement called" << std::endl;
	if (this != &original) {
		*this = original;
	}
	return *this;
}

//----------------- MEMBER FUNCTIONS -----------------//

void		DiamondTrap::attack( const std::string& target )
{

	if (getHitPoint() <= 0) {
		std::cout << "DiamondTrap " << _name << " has no hit point, it cannot act" << std::endl;
		return ;
	}

	if (getEnergyPoint() <= 0) {
		std::cout << "DiamondTrap " << _name << " has no energy left to attack" << std::endl;
		return ;
	}

	setEnergyPoint(getEnergyPoint() - 1);
	std::cout << "DiamondTrap " << _name << " attacks " << target;
	std::cout << " causing " << getAttackDamage() << " points of damage!" << std::endl;
}


void		DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap is " << getName() << " or " << _name << " for short" << std::endl;
}
