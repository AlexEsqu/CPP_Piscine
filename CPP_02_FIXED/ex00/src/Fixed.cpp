#include "Fixed.hpp"

const int	Fixed::_fractional_bit_count = 8;

			Fixed::Fixed( void ): _number_value(0) {
	std::cout << "Default constructor called" << std::endl;
}

			Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
}

			Fixed::Fixed( Fixed& original ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = original;
}

Fixed&	Fixed::operator=( const Fixed& original ) {
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &original) {
		this->_number_value = original.getRawBits();
	}
	return *this;
}

int			Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (_number_value);
}

void		Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	_number_value = raw;
}
