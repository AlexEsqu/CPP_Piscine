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

static void	printNaNorInf( std::string& literal, t_conv& conv )
{
	std::cout << "char: impossible\nint: impossible\nfloat: ";
	if (literal.compare("inf") == 0) {
		if (conv.sign == -1) {std::cout << "-";}
		std::cout << "inf\ndouble: ";
		if (conv.sign == -1) {std::cout << "-";}
		std::cout << "inf\n";
	}
	if (literal.compare("nan") == 0) {
		if (conv.sign == -1) {std::cout << "-";}
		std::cout << "nanf\ndouble: ";
		if (conv.sign == -1) {std::cout << "-";}
		std::cout << "nan\n";
	}
}

static void	setSingleChar( std::string& literal, t_conv& conv )
{
	if (isdigit(literal[0]))
		conv.character = literal[0] - '0';
	else
		conv.character = literal[0];
	conv.large = conv.character;
	conv.dpoint = conv.large;
}

static void	extractSign( std::string& literal, t_conv& conv )
{
	conv.sign = 1;
	if (literal[0] == '-' || literal[0] == '+')
	{
		if (literal[0] == '-')
			conv.sign = -1;
		literal.erase(0, 1);
	}
}

static void	printResults( t_conv conv )
{
	std::cout << "char: ";
	if (conv.character < 0) {std::cout << "impossible";}
	else if (!isprint(conv.character)) {std::cout << "Non displayable";}
	else {std::cout << "'" << (char)conv.character << "'";}

	std::cout << std::endl << "int: ";
	if (conv.large > std::numeric_limits<int>::max()
		|| conv.large < std::numeric_limits<int>::min())
		std::cout << "impossible";
	else
		std::cout << (int)(conv.large) << std::endl;

	std::cout << "float: ";
	if (conv.dpoint > std::numeric_limits<float>::max()
		|| conv.dpoint < std::numeric_limits<float>::min())
		std::cout << "impossible";
	else
		std::cout << std::fixed << std::setprecision(1) << conv.dpoint << "f";

	std::cout << std::endl << "double: ";
	if (conv.dpoint > std::numeric_limits<double>::max()
		|| conv.dpoint < std::numeric_limits<double>::min())
		std::cout << "impossible" << std::endl;
	else
		std::cout << conv.dpoint << std::endl;
}

void		ScalarConverter::convert( std::string literal )
{
	t_conv	conv;

	if (!syntaxCheck(literal))
		return;

	extractSign(literal, conv);

	if (isalpha(literal[0])) {
		if (literal.compare("inf") == 0 || literal.compare("nan") == 0) {
			printNaNorInf(literal, conv);
			return;
		}
		else if (literal.length() == 1 && conv.sign == 1)
			setSingleChar(literal, conv);
		else {
			std::cerr << "ERROR: Unsupported input." << std::endl;
			return;
		}
	}

	else if (literal.find(".")) {
		conv.dpoint = std::atof(literal.c_str());
		conv.large = (long long)conv.dpoint;
	}

	else
		conv.large = std::atoll(literal.c_str());

	conv.large *= conv.sign;
	conv.dpoint *= conv.sign;

	if (conv.large >= 0 && conv.large <= 128)
		conv.character = (char)conv.large;
	else { conv.character = -1; }

	printResults(conv);

}
