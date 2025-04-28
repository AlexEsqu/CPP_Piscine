#include "ClapTrap.hpp"

//----------------- CONSTRUCTORS ---------------------//

ClapTrap::ClapTrap( std::string name )
	: _name(name)
	, _hit_point(CLAPTRAP_HITPOINT)
	, _energy_point(CLAPTRAP_ENERGY)
	, _attack_damage(CLAPTRAP_ATTACK)
{
	std::cout << GREEN << FAINT << "ClapTrap constructor called for ";
	std::cout << _name << STOP_COLOR << STOP_STYLE << std::endl;
}

//----------------- DESTRUCTOR -----------------------//

ClapTrap::~ClapTrap()
{
	std::cout << RED << FAINT << "ClapTrap destructor called" << std::endl;
}

//----------------- COPY CONSTRUCTORS ----------------//

ClapTrap::ClapTrap( const ClapTrap& original )
	: _name(original._name)
	, _hit_point(original.getHitPoint())
	, _energy_point(original.getEnergyPoint())
	, _attack_damage(original.getAttackDamage())
{
	std::cout << GREEN << FAINT << "ClapTrap copy constructor called";
	std::cout << STOP_COLOR << STOP_STYLE << std::endl;
}

//----------------- COPY ASSIGNEMENT -----------------//

ClapTrap&		ClapTrap::operator=( const ClapTrap& original )
{
	std::cout << GREEN << FAINT << "ClapTrap copy assignement called";
	std::cout << STOP_COLOR << STOP_STYLE << std::endl;

	// self reference guard (unneeded unless managing memory)
	if (this == &original)
		return *this;

	_name = original._name;
	_hit_point = original._hit_point;
	_energy_point = original._energy_point;
	_attack_damage = original._attack_damage;
	return *this;
}

//----------------- MEMBER FUNCTIONS -----------------//

void			ClapTrap::attack( const std::string& target )
{

	if (_hit_point <= 0) {
		std::cout << "ClapTrap " << _name << " has no hit point, it cannot act" << std::endl;
		return ;
	}

	if (_energy_point <= 0) {
		std::cout << "ClapTrap " << _name << " has no energy left to attack" << std::endl;
		return ;
	}

	_energy_point--;
	std::cout << "ClapTrap " << _name << " attacks " << target;
	std::cout << " causing " << _attack_damage << " points of damage!" << std::endl;
}

void			ClapTrap::takeDamage( unsigned int amount )
{

	if (_hit_point <= 0) {
		std::cout << "ClapTrap " << _name << " has no hit point left... It's already dead!" << std::endl;
		return ;
	}

	_hit_point -= amount;
	std::cout << "ClapTrap " << _name << " lost " << amount << " hitpoint, ";
	std::cout << "it now has " << _hit_point << std::endl;
}

void			ClapTrap::beRepaired( unsigned int amount )
{

	if (_hit_point <= 0) {
		std::cout << "ClapTrap " << _name << " has no hit point, it cannot act" << std::endl;
		return ;
	}

	if (_energy_point <= 0) {
		std::cout << "ClapTrap " << _name << " has no energy left to repair itself" << std::endl;
		return ;
	}

	_hit_point += amount;
	_energy_point--;
	std::cout << "ClapTrap " << _name << " repaired itself " << amount;
	std::cout << " hitpoint, it now has " << _hit_point << std::endl;
}

std::string		ClapTrap::getName() const
{
	return (_name);
}

int				ClapTrap::getHitPoint() const
{
	return (_hit_point);
}

int				ClapTrap::getEnergyPoint() const
{
	return (_energy_point);
}

int				ClapTrap::getAttackDamage() const
{
	return (_attack_damage);
}

void			ClapTrap::setHitPoint( int new_hit_point )
{
	_hit_point = new_hit_point;
}

void			ClapTrap::setEnergyPoint( int new_energy_point )
{
	_energy_point = new_energy_point;
}

void			ClapTrap::setAttackDamage( int new_attack_damage )
{
	_attack_damage = new_attack_damage;
}

void			ClapTrap::resetHitPoint()
{
	setHitPoint(CLAPTRAP_HITPOINT);
}

void			ClapTrap::resetEnergyPoint()
{
	setEnergyPoint(CLAPTRAP_ENERGY);
}

void			ClapTrap::resetAttackDamage()
{
	setAttackDamage(CLAPTRAP_ATTACK);
}

void			ClapTrap::displayStats()
{
	std::cout << getName() << " has the following attributes : " << std::endl;
	std::cout << "Hit Points [" << getHitPoint();
	std::cout << "] Energy Points [" << getEnergyPoint();
	std::cout << "] Attack Damage [" << getAttackDamage() << "]" << std::endl;
}
