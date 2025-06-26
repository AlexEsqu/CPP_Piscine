#include "Cat.hpp"
#include "Brain.hpp"

//----------------- CONSTRUCTORS ---------------------//

Cat::Cat()
	: Animal()
	, _brain(NULL)
{
	std::cout << "Calling Cat constructor for " << type << std::endl;
	setType("Cat");
	_brain = new Brain();
}

//----------------- DESTRUCTOR -----------------------//
Cat::~Cat()
{
	std::cout << "Calling Cat destructor for " << type << std::endl;
	delete _brain;
}

//----------------- COPY CONSTRUCTORS ----------------//
Cat::Cat( const Cat& original )
	: Animal()
	, _brain(NULL)
{
	std::cout << "Calling Cat copy constructor for " << type << std::endl;
	*this = original;
}

//----------------- COPY ASSIGNEMENT -----------------//
Cat&			Cat::operator=( const Cat& original )
{
	std::cout << "Calling Cat copy assignment for " << type << std::endl;

	if (this == &original)
		return *this;

	Animal::operator=(original);

	if (_brain)
		delete _brain;
	_brain = new Brain(*original._brain);

	return *this;
}

//----------------- MEMBER FUNCTIONS -----------------//
void			Cat::makeSound() const
{
	std::cout << "🐈 Mrrraw~~ " << std::endl;
}

std::string		Cat::getType() const
{
	return (type);
}

void			Cat::addIdea( std::string idea, unsigned int index )
{
	if (index > 100) {
		std::cout << "Idea is outside the box!!!" << std::endl;
		return ;
	}
	_brain->ideas[index] = idea;
}

std::string		Cat::getIdea( unsigned int index )
{
	if (index > 100) {
		std::cout << "Idea is outside the box!!!" << std::endl;
		return NULL;
	}
	return _brain->ideas[index];
}
