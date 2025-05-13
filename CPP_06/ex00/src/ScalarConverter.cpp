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

static void	setNaNorInf( std::string& literal, t_conv& conv )
{
	if (literal.compare("inf") == 0) {
		conv.isInf = true;
		conv.large = std::numeric_limits<long long>::infinity();
		conv.dpoint = std::numeric_limits<double>::infinity();
	}
	if (literal.compare("nan") == 0) {
		conv.isNan = true;
		conv.large = std::numeric_limits<long long>::signaling_NaN();
		conv.dpoint = std::numeric_limits<double>::signaling_NaN();
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

t_conv		ScalarConverter::convert( std::string literal )
{
	t_conv	conv;

	if (!syntaxCheck(literal)) {
		conv.isInvalid = true;
		return conv;
	}

	extractSign(literal, conv);

	if (isalpha(literal[0])) {
		if (literal.compare("inf") == 0 || literal.compare("nan") == 0) {
			setNaNorInf(literal, conv);
		}
		else if (literal.length() == 1 && conv.sign == 1)
			setSingleChar(literal, conv);
		else {
			std::cerr << "ERROR: Unsupported input." << std::endl;
			conv.isInvalid = true;
		}
	}

	else if (literal.find(".")) {
		conv.dpoint = std::atof(literal.c_str()) * conv.sign;
		conv.large = (long long)conv.dpoint * conv.sign;
	}

	else {
		conv.large = std::atoll(literal.c_str()) * conv.sign;
		conv.dpoint = conv.large * conv.sign;
	}

	if (conv.large >= 0 && conv.large <= 128)
		conv.character = (char)conv.large;
	else { conv.character = -1; }

	return (conv);
}
