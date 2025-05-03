#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	if (DEBUG) {
		std::cout << GREEN << "[SCALAR] Calling Constructor";
		std::cout << STOP_COLOR << std::endl;
	}
}

ScalarConverter::~ScalarConverter()
{
	if (DEBUG) {
		std::cout << RED << "[SCALAR] Calling Destructor";
		std::cout << STOP_COLOR << std::endl;
	}
}

ScalarConverter::ScalarConverter( const ScalarConverter& )
{
	if (DEBUG) {
		std::cout << GREEN << "[SCALAR] Calling Copy Constructor";
		std::cout << STOP_COLOR << std::endl;
	}
}

ScalarConverter&	ScalarConverter::operator=( const ScalarConverter& )
{
	if (DEBUG) {
		std::cout << GREEN << "[SCALAR] Calling Copy Assignement";
		std::cout << STOP_COLOR << std::endl;
	}
	return *this;
}

static bool	syntaxCheck( std::string literal )
{
	if (literal.empty())
	{
		std::cerr << RED << "ERROR: There is nothing to convert.";
		std::cerr << STOP_COLOR << std::endl;
		return false;
	}

	for (size_t i = 0; i < literal.length(); i++) {
		if (!isascii(literal[i]))
		{
			std::cerr << RED << "ERROR: Non supported character.";
			std::cerr << STOP_COLOR << std::endl;
			return false;
		}
	}

	return true;
}

static bool	isNumOrSingleChar( std::string& literal )
{
	if (literal.length() > 1 && !isdigit(literal[1])) {
		std::cerr << "ERROR: Unsupported input." << std::endl;
		return false;
	}
	return true;
}

static int	extractSign( std::string& literal )
{
	int	sign;

	sign = 1;
	if (literal[0] == '-' || literal[0] == '+')
	{
		if (literal[0] == '-')
			sign = -1;
		literal.erase(0, 1);
	}
	return sign;
}

static void	printResults( t_conv conv )
{
	std::cout << "char: ";
	if (conv.character == -1)
		std::cout << "impossible";
	else if (!isprint(conv.character))
		std::cout << "Non displayable";
	else
		std::cout << "'" << (char)conv.character << "'";

	std::cout << std::endl << "int: ";
	if (conv.integer == -1)
		std::cout << "impossible";
	else
		std::cout << (int)(conv.large * (long long)conv.sign);

	std::cout << std::endl << "float: ";
	if (conv.fpoint == -1)
		std::cout << "impossible";
	else
		std::cout << (float)(conv.dpoint * conv.sign) << "f";

	std::cout << std::endl << "double: ";
	if (conv.dpoint == -1)
		std::cout << "impossible";
	else
		std::cout << conv.dpoint * conv.sign;
	std::cout << std::endl;
}

void		ScalarConverter::convert( std::string literal )
{
	t_conv	conv;

	if (!syntaxCheck(literal))
		return;

	conv.sign = extractSign(literal);

	if (literal.compare("inf") == 0) {
		conv.isInf = true;
	}
	else if (literal.compare("nan") == 0) {
		conv.isNan = true;
	}
	else if (!isNumOrSingleChar(literal)) {
		return;
	}

	conv.character = -1;
	if (literal.length() == 1 && conv.sign == 1) {
		conv.character = literal[0];
		conv.large = conv.character;
		conv.dpoint = conv.large;
	}
	else if (literal.find(".")) {
		conv.dpoint = std::atof(literal.c_str());
		conv.large = (long long)conv.dpoint;
	}
	else
		conv.large = std::atoll(literal.c_str());

	printResults(conv);

}
