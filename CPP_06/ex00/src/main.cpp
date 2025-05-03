#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout << RED << "Please input a  single value to convert.";
		std::cout << STOP_COLOR << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}
