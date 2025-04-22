#include "ClapTrap.hpp"

//----------------- CONSTRUCTORS ---------------------//
			ClapTrap::ClapTrap():
			_name("Generic"), _hit_point(10), _energy_point(10), _attack_damage(0) {
	std::cout << "Default ClapTrap constructor called" << std::endl;
}

			ClapTrap::ClapTrap( std::string name):
			_name(name), _hit_point(10), _energy_point(10), _attack_damage(0) {
	std::cout << "Named ClapTrap constructor called for " << _name << std::endl;
}

//----------------- DESTRUCTOR -----------------------//

			ClapTrap::~ClapTrap() {
	std::cout << "Default ClapTrap destructor called" << std::endl;
}

//----------------- COPY CONSTRUCTORS ----------------//

			ClapTrap::ClapTrap( const ClapTrap& original ):
			_name(original._name), _hit_point(original._hit_point),
			_energy_point(original._energy_point), _attack_damage(original._attack_damage) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

//----------------- COPY ASSIGNEMENT -----------------//

ClapTrap&	ClapTrap::operator=( const ClapTrap& original ) {
	std::cout << "ClapTrap copy assignement called" << std::endl;
	if (this != &original) {
		_name = original._name;
		_hit_point = original._hit_point;
		_energy_point = original._energy_point;
		_attack_damage = original._attack_damage;
	}
	return *this;
}

//----------------- MEMBER FUNCTIONS -----------------//

void		ClapTrap::attack( const std::string& target ) {

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

void		ClapTrap::takeDamage( unsigned int amount ) {

	if (_hit_point <= 0) {
		std::cout << "ClapTrap " << _name << " has no hit point left... It's already dead!" << std::endl;
		return ;
	}

	_hit_point -= amount;
	std::cout << "ClapTrap " << _name << " lost " << amount << " hitpoint, ";
	std::cout << "it now has " << _hit_point << std::endl;
}

void		ClapTrap::beRepaired( unsigned int amount ) {

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
