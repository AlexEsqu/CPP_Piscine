#include "Harl.hpp"

int	main( void )
{
	Harl	harl;
	std::cout << std::endl << "Let's give Harl the string 'DEBUG':" << std::endl;
	harl.complain("DEBUG");

	std::cout << std::endl << "Let's give Harl the string 'INFO' :" << std::endl;
	harl.complain("INFO");

	std::cout << std::endl << "Let's give Harl the string 'WARNING' :" << std::endl;
	harl.complain("WARNING");

	std::cout << std::endl << "Let's give Harl the string 'ERROR' :" << std::endl;
	harl.complain("ERROR");

	std::cout << std::endl << "Let's give Harl the string 'INVALID' :" << std::endl;
	harl.complain("INVALID");

	std::cout << std::endl << "By matching the string to a member function pointer, ";
	std::cout << "we can avoid an endless if/else forest!" << std::endl << std::endl;

	return (0);
}
