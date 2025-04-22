#include "Fixed.hpp"

//------------- VARIABLE INITALISATION ---------------//

const int	Fixed::_fractional_bit_count = 8;

//----------------- CONSTRUCTORS ---------------------//

			Fixed::Fixed( void ): _number_value(0) {
	std::cout << "Default constructor called" << std::endl;
}

			Fixed::Fixed( const int num ): _number_value(num << _fractional_bit_count) {
	std::cout << "Int constructor called" << std::endl;
}

			Fixed::Fixed( const float fnum ): _number_value(roundf(fnum * (1 << _fractional_bit_count))) {
	std::cout << "Float constructor called" << std::endl;
}

//----------------- DESTRUCTOR -----------------------//

			Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
}

//----------------- COPY CONSTRUCTORS ----------------//

			Fixed::Fixed( const Fixed& original ): _number_value(original._number_value) {
	std::cout << "Copy constructor called" << std::endl;
}

//----------------- COPY ASSIGNEMENT -----------------//

Fixed&	Fixed::operator=( const Fixed& original ) {
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &original) {
		this->_number_value = original.getRawBits();
	}
	return *this;
}

//----------------- MEMBER FUNCTIONS -----------------//

int			Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (_number_value);
}

void		Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	_number_value = raw;
}

float		Fixed::toFloat( void ) const {
	float	result = (float)_number_value / (float)(1 << _fractional_bit_count);
	return (result);
}

int			Fixed::toInt( void ) const {
	int	result = _number_value >> _fractional_bit_count;
	return (result);
}

int			Fixed::getFactionalBitCount( void ) {
	std::cout << "Accessing _fractional_bit_count: " << _fractional_bit_count << std::endl;
	return _fractional_bit_count;
}


//----------------- REPRESENTATION -----------------//

std::ostream& operator<<( std::ostream& out, const Fixed& point ) {
	out << point.toFloat();
	return (out);
}
