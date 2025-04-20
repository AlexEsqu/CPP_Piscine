#ifndef FIXED_POINT_CLASS_H
# define FIXED_POINT_CLASS_H

# include <iostream>

class	Fixed
{

public:

	//----------------- CONSTRUCTORS ---------------------//
						Fixed( void );
						Fixed( const int );
						Fixed( const float );

	//----------------- DESTRUCTOR -----------------------//
						~Fixed( void );

	//----------------- COPY CONSTRUCTORS ----------------//
						Fixed( Fixed& original );

	//----------------- COPY ASSIGNEMENT -----------------//
	Fixed&				operator=( const Fixed& original );

	//----------------- MEMBER FUNCTIONS -----------------//
	int					getRawBits( void ) const;
	void				setRawBits( int const raw );
	float				toFloat( void ) const;
	int					toInt( void ) const;

private:

	int					_number_value;
	static const int	_fractional_bit_count;

};




#endif
