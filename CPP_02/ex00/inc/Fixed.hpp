#ifndef FIXED_POINT_CLASS_H
# define FIXED_POINT_CLASS_H

# include <iostream>

class	Fixed
{

public:
						Fixed( void );
						~Fixed( void );
						Fixed( Fixed& original );
	Fixed&			operator=( const Fixed& original );
	int					getRawBits( void ) const;
	void				setRawBits( int const raw );

private:

	int					_number_value;
	static const int	_fractional_bit_count;

};




#endif
