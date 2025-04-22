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

	//----------------- MEMBER FUNCTIONS -----------------//
	int					getRawBits( void ) const;
	void				setRawBits( int const raw );
	float				toFloat( void ) const;
	int					toInt( void ) const;
	int					getFactionalBitCount( void );

private:

	int					_number_value;
	static const int	_fractional_bit_count;

};

std::ostream& operator<<( std::ostream& out, const Fixed& point );

#endif
