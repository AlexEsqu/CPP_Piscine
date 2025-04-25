#include "ScavTrap.hpp"

//----------------- CONSTRUCTORS ---------------------//

ScavTrap::ScavTrap( std::string name)
	: ClapTrap(name)
{
	std::cout << GREEN << FAINT << "ScavTrap constructor called for ";
	std::cout << name << STOP_COLOR << STOP_STYLE << std::endl;

	setHitPoint(100);
	setEnergyPoint(50);
	setAttackDamage(20);
}

//----------------- DESTRUCTOR -----------------------//

ScavTrap::~ScavTrap()
{
	std::cout << RED << FAINT << "ScavTrap destructor called";
	std::cout << STOP_COLOR << STOP_STYLE << std::endl;
}

//----------------- COPY CONSTRUCTORS ----------------//

ScavTrap::ScavTrap( const ScavTrap& original )
	: ClapTrap(original)
{
	std::cout << GREEN << FAINT << "ScavTrap copy constructor called";
	std::cout << STOP_COLOR << STOP_STYLE << std::endl;

	setHitPoint(original.getHitPoint());
	setEnergyPoint(original.getEnergyPoint());
	setAttackDamage(original.getAttackDamage());
}

//----------------- COPY ASSIGNEMENT -----------------//

ScavTrap&	ScavTrap::operator=( const ScavTrap& original )
{
	std::cout << GREEN << FAINT << "ScavTrap copy assignement called";
	std::cout << STOP_COLOR << STOP_STYLE << std::endl;

	ClapTrap::operator=(original);
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
