#ifndef FIXED_POINT_CLASS_H
# define FIXED_POINT_CLASS_H

# include <iostream>
# include <math.h>

class	Fixed
{

public:

	//----------------- CONSTRUCTORS ---------------------//
						Fixed( void );
						Fixed( const int num );
						Fixed( const float fnum );

	//----------------- DESTRUCTOR -----------------------//
						~Fixed( void );

	//----------------- COPY CONSTRUCTORS ----------------//
						Fixed( const Fixed& original );

	//----------------- COPY ASSIGNEMENT -----------------//
	Fixed&				operator=( const Fixed& original );

	//----------------- COMPARISON OPERATOR --------------//
	bool				operator>( const Fixed& comp ) const;
	bool				operator<( const Fixed& comp ) const;
	bool				operator>=( const Fixed& comp ) const;
	bool				operator<=( const Fixed& comp ) const;
	bool				operator==( const Fixed& comp ) const;
	bool				operator!=( const Fixed& comp ) const;

	//----------------- ARITHMETIC OPERATOR --------------//
	Fixed				operator+( const Fixed& comp ) const;
	Fixed				operator-( const Fixed& comp ) const;
	Fixed				operator*( const Fixed& comp ) const;
	Fixed				operator/( const Fixed& comp ) const;

	//----------------- INCREMENT OPERATOR --------------//
	Fixed&				operator++( void );
	Fixed&				operator--( void );
	Fixed				operator++( int );
	Fixed				operator--( int );

	//----------------- MEMBER FUNCTIONS -----------------//
	int					getRawBits( void ) const;
	void				setRawBits( int const raw );
	float				toFloat( void ) const;
	int					toInt( void ) const;

	//----------------- STATIC MEMBER FUNCTIONS ----------//
	static Fixed&		min( Fixed& a, Fixed& b);
	static const Fixed&	min( const Fixed& a, const Fixed& b);
	static Fixed&		max( Fixed& a, Fixed& b);
	static const Fixed&	max( const Fixed& a, const Fixed& b);

private:

	int					_number_value;
	static const int	_fractional_bit_count;

};

std::ostream& operator<<( std::ostream& out, const Fixed& point );

#endif
