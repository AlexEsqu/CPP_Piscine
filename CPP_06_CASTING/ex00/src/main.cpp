#include "ScalarConverter.hpp"

static void	printResults( t_conv conv )
{
	std::cout << "char: ";
	if (conv.isInvalidChar) {std::cout << "impossible";}
	else if (!isprint(conv.character)) {std::cout << "Non displayable";}
	else {std::cout << "'" << static_cast<char>(conv.character) << "'";}

	std::cout << std::endl << "int: ";
	if (conv.isInvalidInt) {std::cout << "impossible";}
	else {std::cout << conv.integer;}

	std::cout << std::endl << "float: ";
	if (conv.isInvalidFloat) {std::cout << "impossible";}
	else {
		std::cout << std::fixed << std::setprecision(1) << conv.fpoint;
		std::cout << "f";
	}

	std::cout << std::endl << "double: " << conv.dpoint << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout << RED << "Please input a  single value to convert.";
		std::cout << STOP_COLOR << std::endl;
		return 1;
	}

	t_conv	result;

	try {
		result = ScalarConverter::convert(argv[1]);
		printResults(result);
	}
	catch (const std::exception& e) {
		std::cerr << RED << e.what() << STOP_COLOR << std::endl;
	}
	return 0;
}
