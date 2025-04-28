#include "Character.hpp"

//----------------- CONSTRUCTORS ---------------------//

Character::Character(const std::string& name)
	: _name(name)
{
	if (DEBUG) {
		std::cout << GREEN << "[CHARACTER] Calling Constructor ";
		std::cout << _name << STOP_COLOR << std::endl;
	}

	for (int i = 0; i < 4; i++) {
		_inventory[i] = NULL;
	}
	_drop_list = NULL;

}

//----------------- DESTRUCTOR -----------------------//

Character::~Character()
{

	if (DEBUG) {
		std::cout << RED << "[CHARACTER] Calling Destructor ";
		std::cout << _name << STOP_COLOR << std::endl;
	}

	for (int i = 0; i < 4; i++) {
		if (_inventory[i] != NULL)
			delete _inventory[i];
	}

	Node	*current = _drop_list;
	Node	*next;
	while (current)
	{
		next = current->next;
		delete current;
		current = next;
	}

}

//----------------- COPY CONSTRUCTORS ----------------//

Character::Character( const Character& original )
	: _name(original.getName())
{
	if (DEBUG) {
		std::cout << GREEN << "[CHARACTER] Calling Copy Constructor ";
		std::cout << _name << STOP_COLOR << std::endl;
	}

	for (int i = 0; i < 4; i++) {
		_inventory[i] = original._inventory[i]->clone();
	}

}

//----------------- COPY ASSIGNEMENT -----------------//

Character&				Character::operator=( const Character& original )
{
	if (DEBUG) {
		std::cout << GREEN << "[CHARACTER] Calling Copy Assignement ";
		std::cout << _name << STOP_COLOR << std::endl;
	}

	if (this == &original)
		return *this;

	_name = original.getName();

	for (int i = 0; i < 4; i++) {
		_inventory[i] = original._inventory[i]->clone();
	}

	return *this;
}

//----------------- MEMBER FUNCTIONS -----------------//

const std::string&		Character::getName() const
{
	return (_name);
}

void					Character::equip(AMateria* m)
{
	if (DEBUG) {
		std::cout << YELLOW << "[CHARACTER] " << _name << " equiping Materia ";
		std::cout << m->getType() << STOP_COLOR << std::endl;
	}

	for (int i = 0; i < 4; i++) {
		if (_inventory[i] == NULL) {
			_inventory[i] = m;
			return ;
		}
	}

	if (DEBUG) {
		std::cout << RED << "[CHARACTER] " << _name << "'s inventory is full";
		std::cout << STOP_COLOR << std::endl;
	}
}

void 					Character::unequip(int idx)
{
	if (DEBUG) {
		std::cout << YELLOW << "[CHARACTER] " << _name << " unequiping their ";
		std::cout << idx << " Materia" << STOP_COLOR << std::endl;
	}

	if (DEBUG && (idx < 0 || idx > 3))
		std::cout << RED << "Materia is out of bounds !" << STOP_COLOR << std::endl;
	else if (DEBUG && (_inventory[idx] == NULL))
		std::cout << RED << "Materia does not exist !" << STOP_COLOR << std::endl;
	else
		drop(idx);
}

void					Character::use( int idx, ICharacter& target )
{
	if (DEBUG) {
		std::cout << MAGENTA << "[CHARACTER] " << _name << " is using their ";
		std::cout << idx << " Materia" << STOP_COLOR << std::endl;
	}

	if (DEBUG && (idx < 0 || idx > 3))
		std::cout << RED << "Materia is out of bounds !" << STOP_COLOR << std::endl;
	else
		_inventory[idx]->use(target);
}


void					Character::drop( int idx )
{
	AMateria*	to_drop = _inventory[idx];

	_inventory[idx] = NULL;

	std::cout << YELLOW << "[CHARACTER] " << _name << " dropped a ";
	std::cout << to_drop->getType() << " Materia" << STOP_COLOR << std::endl;

	Node*		drop_spot = _drop_list;

	while (drop_spot && drop_spot->next != NULL)
		drop_spot = drop_spot->next;

	_drop_list = new Node;
	_drop_list->materia = to_drop;
	_drop_list->next = NULL;

}
