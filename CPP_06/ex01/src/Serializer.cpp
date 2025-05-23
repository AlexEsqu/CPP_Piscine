#include "Serializer.hpp"

Serializer::Serializer()
{
	if (DEBUG) {
		std::cout << GREEN << "[SCALAR] Calling Constructor";
		std::cout << STOP_COLOR << std::endl;
	}
}

Serializer::~Serializer()
{
	if (DEBUG) {
		std::cout << RED << "[SCALAR] Calling Destructor";
		std::cout << STOP_COLOR << std::endl;
	}
}

Serializer::Serializer( const Serializer& )
{
	if (DEBUG) {
		std::cout << GREEN << "[SCALAR] Calling Copy Constructor";
		std::cout << STOP_COLOR << std::endl;
	}
}

Serializer&	Serializer::operator=( const Serializer& )
{
	if (DEBUG) {
		std::cout << GREEN << "[SCALAR] Calling Copy Assignement";
		std::cout << STOP_COLOR << std::endl;
	}
	return *this;
}

uintptr_t	Serializer::serialize( Data* ptr ) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*		Serializer::deserialize( uintptr_t raw ) {
	return (reinterpret_cast<Data*>(raw));
}
