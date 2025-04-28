#include "Harl.hpp"

int	main( int argc, char **argv )
{
	if (argc != 2)
		return (1);

	Harl		harl;
	std::string	log_level = argv[1];

	harl.complain(log_level);

	return (0);
}
