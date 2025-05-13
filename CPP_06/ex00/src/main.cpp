#include "ScalarConverter.hpp"

static void	printResults( t_conv conv )
{
	std::cout << "char: ";
	if (conv.character < 0 || conv.sign == -1 ) {std::cout << "impossible";}
	else if (!isprint(conv.character)) {std::cout << "Non displayable";}
	else {std::cout << "'" << (char)conv.character << "'";}

	std::cout << std::endl << "int: ";
	if (conv.large > std::numeric_limits<int>::max()
		|| conv.large < std::numeric_limits<int>::min())
		std::cout << "impossible";
	else
		std::cout << (int)(conv.large) << std::endl;

	std::cout << "float: ";
	// if (conv.dpoint > std::numeric_limits<float>::max()
	// 	|| conv.dpoint < std::numeric_limits<float>::min())
	// 	std::cout << "impossible";
	// else
		std::cout << std::fixed << std::setprecision(1) << conv.dpoint << "f";

	std::cout << std::endl << "double: ";
	// if (conv.dpoint > std::numeric_limits<double>::max()
	// 	|| conv.dpoint < std::numeric_limits<double>::min())
	// 	std::cout << "impossible" << std::endl;
	// else
		std::cout << conv.dpoint << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout << RED << "Please input a  single value to convert.";
		std::cout << STOP_COLOR << std::endl;
		return 1;
	}

	t_conv	result;

	result = ScalarConverter::convert(argv[1]);
	printResults(result);
	return 0;
}
