#include "Dog.hpp"
#include "Brain.hpp"

//----------------- CONSTRUCTORS ---------------------//

Dog::Dog()
	: Animal()
	, _brain(NULL)
{
	std::cout << "Calling Dog constructor for " << type << std::endl;
	setType("Dog");
	_brain = new Brain();
}

//----------------- DESTRUCTOR -----------------------//
Dog::~Dog()
{
	std::cout << "Calling Dog destructor for " << type << std::endl;
	delete _brain;
}

//----------------- COPY CONSTRUCTORS ----------------//
Dog::Dog( const Dog& original )
	: Animal(original)
	, _brain(NULL)
{
	std::cout << "Calling Dog copy constructor for " << type << std::endl;
	*this = original;
}

//----------------- COPY ASSIGNEMENT -----------------//
Dog&			Dog::operator=( const Dog& original )
{
	std::cout << "Calling Dog copy assignment for " << type << std::endl;

	if (this == &original)
		return *this;

	Animal::operator=(original);

	if (_brain)
		delete _brain;
	_brain = new Brain(*original._brain);

	return *this;
}

//----------------- MEMBER FUNCTIONS -----------------//
void			Dog::makeSound() const
{
	std::cout << "🐕 Wooffff! " << std::endl;
}

std::string		Dog::getType() const
{
	return (type);
}

void			Dog::addIdea( std::string idea, unsigned int index )
{
	if (index > 100) {
		std::cout << "Idea is outside the box!!!" << std::endl;
		return ;
	}
	_brain->ideas[index] = idea;
}

std::string		Dog::getIdea( unsigned int index )
{
	if (index > 100) {
		std::cout << "Idea is outside the box!!!" << std::endl;
		return NULL;
	}
	return _brain->ideas[index];
}
