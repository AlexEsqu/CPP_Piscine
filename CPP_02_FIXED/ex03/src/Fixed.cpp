#include "Fixed.hpp"

//------------- VARIABLE INITALISATION ---------------//

const int	Fixed::_fractional_bit_count = 8;

//----------------- CONSTRUCTORS ---------------------//

			Fixed::Fixed(): _number_value(0) {
	// std::cout << "Default constructor called" << std::endl;
}

			Fixed::Fixed( const int num ): _number_value(num << _fractional_bit_count) {
	// std::cout << "Int constructor called" << std::endl;
}

			Fixed::Fixed( const float fnum ): _number_value(roundf(fnum * (1 << _fractional_bit_count))) {
	// std::cout << "Float constructor called" << std::endl;
}

//----------------- DESTRUCTOR -----------------------//

			Fixed::~Fixed() {
	// std::cout << "Destructor called" << std::endl;
}

//----------------- COPY CONSTRUCTORS ----------------//

			Fixed::Fixed( const Fixed& original ): _number_value(original._number_value) {
	// std::cout << "Copy constructor called" << std::endl;
}

//----------------- COPY ASSIGNEMENT -----------------//

Fixed&		Fixed::operator=( const Fixed& original ) {
	// std::cout << "Copy assignement operator called" << std::endl;
	if (this != &original) {
		this->_number_value = original.getRawBits();
	}
	return *this;
}

//----------------- COMPARISON OPERATOR --------------//

bool		Fixed::operator>( const Fixed& comp ) const {
	return (_number_value > comp._number_value);
}

bool		Fixed::operator<( const Fixed& comp ) const {
	return (_number_value < comp._number_value);
}

bool		Fixed::operator>=( const Fixed& comp ) const {
	return (_number_value >= comp._number_value);
}

bool		Fixed::operator<=( const Fixed& comp ) const {
	return (_number_value <= comp._number_value);
}

bool		Fixed::operator==( const Fixed& comp ) const {
	return (_number_value == comp._number_value);
}

bool		Fixed::operator!=( const Fixed& comp ) const {
	return (_number_value != comp._number_value);
}

//----------------- ARITHMETIC OPERATOR --------------//

Fixed		Fixed::operator+( const Fixed& comp ) const {
	Fixed	result;
	result._number_value = (_number_value + comp._number_value);
	return (result);
}

Fixed		Fixed::operator-( const Fixed& comp ) const {
	Fixed	result;
	result._number_value = (_number_value - comp._number_value);
	return (result);
}


// multiplying 1.00 by 1.00 is not 10 000
// using temp long long to avoid overflow during multiplication
Fixed		Fixed::operator*( const Fixed& comp ) const {

	long long	temp;
	temp = (_number_value * (long long)comp._number_value) >> _fractional_bit_count;

	// or, alternatively :
	// temp = (long long)_number_value * comp.toFloat();

	Fixed		result;
	result._number_value = (int)temp;

	return (result);
}

Fixed		Fixed::operator/( const Fixed& comp ) const {

	if (comp._number_value == 0) {
		std::cout << "uhmmmm.... division by zero is risky !!! But I'll allow it to see the crash happen :D" << std::endl;
	}

	long long	temp;
	temp = ((long long)_number_value << _fractional_bit_count) / (long long)comp._number_value;

	// or, alternatively :
	// temp = (long long)_number_value / comp.toFloat();

	Fixed		result;
	result._number_value = (int)temp;

	return (result);
}

//----------------- INCREMENT OPERATOR --------------//

Fixed&		Fixed::operator++() {
	_number_value++;
	return (*this);
}

Fixed&		Fixed::operator--() {
	_number_value--;
	return (*this);
}

Fixed		Fixed::operator++( int ) {
	Fixed	result;
	result._number_value = _number_value;
	_number_value++;
	return (result);
}

Fixed		Fixed::operator--( int ) {
	Fixed	result;
	result._number_value = _number_value;
	_number_value--;
	return (result);
}

//----------------- MEMBER FUNCTIONS -----------------//

int			Fixed::getRawBits() const {
	return (_number_value);
}

void		Fixed::setRawBits( int const raw ) {
	_number_value = raw;
}

float		Fixed::toFloat() const {
	float	result = (float)_number_value / (float)(1 << _fractional_bit_count);
	return (result);
}

int			Fixed::toInt() const {
	int	result = _number_value >> _fractional_bit_count;
	return (result);
}

//----------------- STATIC MEMBER FUNCTIONS ----------//

Fixed&		Fixed::min( Fixed& a, Fixed& b) {
	if (a._number_value < b._number_value)
		return (a);
	else
		return (b);
}

const Fixed&		Fixed::min( const Fixed& a, const Fixed& b) {
	if (a._number_value < b._number_value)
		return (a);
	else
		return (b);
}

Fixed&		Fixed::max( Fixed& a, Fixed& b) {
	if (a._number_value > b._number_value)
		return (a);
	else
		return (b);
}

const Fixed&		Fixed::max( const Fixed& a, const Fixed& b) {
	if (a._number_value > b._number_value)
		return (a);
	else
		return (b);
}


//----------------- REPRESENTATION -----------------//

std::ostream& operator<<( std::ostream& out, const Fixed& point ) {
	out << point.toFloat();
	return (out);
}
