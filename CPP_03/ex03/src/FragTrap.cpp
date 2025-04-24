#include "FragTrap.hpp"

//----------------- CONSTRUCTORS ---------------------//

FragTrap::FragTrap( std::string name)
	: ClapTrap(name)
{
	std::cout << "FragTrap constructor called for " << name << std::endl;

	setHitPoint(100);
	setEnergyPoint(100);
	setAttackDamage(30);
}

//----------------- DESTRUCTOR -----------------------//

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

//----------------- COPY CONSTRUCTORS ----------------//

FragTrap::FragTrap( const FragTrap& original )
	: ClapTrap(original)
{
	std::cout << "FragTrap copy constructor called" << std::endl;

	setHitPoint(original.getHitPoint());
	setEnergyPoint(original.getEnergyPoint());
	setAttackDamage(original.getAttackDamage());

}

//----------------- COPY ASSIGNEMENT -----------------//

FragTrap&	FragTrap::operator=( const FragTrap& original )
{
	std::cout << "FragTrap copy assignement called" << std::endl;
	if (this != &original) {
		*this = original;
	}
	return *this;
}

//----------------- MEMBER FUNCTIONS -----------------//

void		FragTrap::attack( const std::string& target )
{

	if (getHitPoint() <= 0) {
		std::cout << "FragTrap " << getName() << " has no hit point, it cannot act" << std::endl;
		return ;
	}

	if (getEnergyPoint() <= 0) {
		std::cout << "FragTrap " << getName() << " has no energy left to attack" << std::endl;
		return ;
	}

	setEnergyPoint(getEnergyPoint() - 1);
	std::cout << "FragTrap " << getName() << " attacks " << target;
	std::cout << " causing " << getAttackDamage() << " points of damage!" << std::endl;
}

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
