#include "MateriaSource.hpp"

//----------------- CONSTRUCTORS ---------------------//

MateriaSource::MateriaSource()
{
	if (DEBUG)
		std::cout << GREEN << "[MATERIASOURCE] Constructor" << STOP_COLOR << std::endl;

	for (int i = 0; i < 4; i++) {
		_learned[i] = NULL;
	}
}

//----------------- DESTRUCTOR -----------------------//

MateriaSource::~MateriaSource()
{
	if (DEBUG) {
		std::cout << RED << "[MATERIASOURCE] Destructor";
		std::cout << STOP_COLOR << std::endl;
	}

	for (int i = 0; i < 4; i++) {
		if (_learned[i] != NULL)
			delete _learned[i];
	}
}

//----------------- COPY CONSTRUCTORS ----------------//

MateriaSource::MateriaSource( const MateriaSource& original )
{
	if (DEBUG) {
		std::cout << GREEN << "[MATERIASOURCE] Copy Constructor";
		std::cout << STOP_COLOR << std::endl;
	}

	for (int i = 0; i < 4; i++) {
		_learned[i] = original._learned[i];
	}
}

//----------------- COPY ASSIGNEMENT -----------------//

MateriaSource&	MateriaSource::operator=( const MateriaSource& original )
{
	if (DEBUG) {
		std::cout << GREEN << "[MATERIASOURCE] Copy Assignement";
		std::cout << STOP_COLOR << std::endl;
	}

	for (int i = 0; i < 4; i++) {
		_learned[i] = original._learned[i];
	}
	return *this;
}

//----------------- MEMBER FUNCTIONS -----------------//

void			MateriaSource::learnMateria( AMateria* m )
{
	if (DEBUG) {
		std::cout << GREEN << "[MATERIASOURCE] Learning Materia of type ";
		std::cout << m->getType() << STOP_COLOR << std::endl;
	}

	for (int i = 0; i < 4; i++) {
		if (_learned[i] == NULL) {
			_learned[i] = m;
			return ;
		}
	}

	if (DEBUG) {
		std::cout << RED << "[MATERIASOURCE] Source already contains";
		std::cout << " 4 Materia" << STOP_COLOR << std::endl;
	}

	delete m;

}

AMateria*		MateriaSource::createMateria( const std::string& type )
{
	if (DEBUG) {
		std::cout << GREEN << "[MATERIASOURCE] Creating Materia of type ";
		std::cout << type << STOP_COLOR << std::endl;
	}

	for (int i = 0; i < 4; i++) {
		if (_learned[i] != NULL
			&& _learned[i]->getType().compare(type) == 0) {
			AMateria	*pNewMateria = _learned[i]->clone();
			return (pNewMateria);
		}
	}

	if (DEBUG) {
		std::cout << RED << "[MATERIASOURCE] Materia " << type;
		std::cout << " is unknown" << STOP_COLOR << std::endl;
	}

	return (NULL);
}
