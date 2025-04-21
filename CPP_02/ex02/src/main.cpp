#include "Fixed.hpp"

int	main( void ) {

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	// ADDITIONAL TESTS

	Fixed const c( Fixed( 5.05f ) / Fixed( 2 ) );
	std::cout << "5.05 / 2 = " << c << std::endl;
	Fixed const f( Fixed( 10.25f ) / Fixed( 5 ) );
	std::cout << "10.25 / 5 = " << f << std::endl;
	Fixed d(4000000);
	std::cout << "4 000 000 = " << d << std::endl;
	Fixed const e( Fixed( 1000000 ) * Fixed( 2 ) );
	std::cout << "1 000 000 * 2 = " << e << std::endl;
	// Fixed const boom( Fixed( 5.05f ) / Fixed( 0 ) );
	// std::cout << "5.05 / 0 = " << boom << std::endl;

	return 0;
}
