#include "ScavTrap.hpp"

//----------------- CONSTRUCTORS ---------------------//

ScavTrap::ScavTrap( std::string name)
	: ClapTrap(name)
{
	std::cout << "ScavTrap constructor called for " << name << std::endl;

	setHitPoint(100);
	setEnergyPoint(50);
	setAttackDamage(20);
}

//----------------- DESTRUCTOR -----------------------//

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

//----------------- COPY CONSTRUCTORS ----------------//

ScavTrap::ScavTrap( const ScavTrap& original )
	: ClapTrap(original)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;

	this->setHitPoint(original.getHitPoint());
	this->setEnergyPoint(original.getEnergyPoint());
	this->setAttackDamage(original.getAttackDamage());
}

//----------------- COPY ASSIGNEMENT -----------------//

ScavTrap&	ScavTrap::operator=( const ScavTrap& original )
{
	std::cout << "ScavTrap copy assignement called" << std::endl;
	if (this != &original) {
		*this = original;
	}
	return *this;
}

//----------------- MEMBER FUNCTIONS -----------------//

void		ScavTrap::attack( const std::string& target )
{

	if (getHitPoint() <= 0) {
		std::cout << "ScavTrap " << getName() << " has no hit point, it cannot act" << std::endl;
		return ;
	}

	if (getEnergyPoint() <= 0) {
		std::cout << "ScavTrap " << getName() << " has no energy left to attack" << std::endl;
		return ;
	}

	setEnergyPoint(getEnergyPoint() - 1);
	std::cout << "ScavTrap " << getName() << " attacks " << target;
	std::cout << " causing " << getAttackDamage() << " points of damage!" << std::endl;
}

void		ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << getName() << " is now in Gate keeper mode" << std::endl;
}

void		ScavTrap::resetHitPoint()
{
	setHitPoint(SCAVTRAP_HITPOINT);
}

void		ScavTrap::resetEnergyPoint()
{
	setEnergyPoint(SCAVTRAP_ENERGY);
}

void		ScavTrap::resetAttackDamage()
{
	setAttackDamage(SCAVTRAP_ATTACK);
}
