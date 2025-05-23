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




static void	syntaxCheck( std::string literal )
{
	if (literal.empty())
		throw std::invalid_argument("ERROR: Input is empty.");

	for (size_t i = 0; i < literal.length(); i++) {
		if (!isascii(literal[i]))
			throw std::invalid_argument("ERROR: Unsupported input.");
	}
}

static void	overflowCheck( t_conv& conv )
{
	if (conv.integer <= 0 || conv.integer >= 128)
		conv.isInvalidChar = true;
	if (conv.dpoint > std::numeric_limits<int>::max()
		|| conv.dpoint < std::numeric_limits<int>::min())
		conv.isInvalidInt = true;
	if (conv.dpoint > std::numeric_limits<float>::max()
		|| conv.dpoint < std::numeric_limits<float>::min())
		conv.isInf = true;
}

static void	extractSign( std::string& literal, t_conv& conv )
{
	if (literal[0] == '-' || literal[0] == '+')
	{
		if (literal[0] == '-')
			conv.sign = -1;
		literal.erase(0, 1);
		conv.isInvalidChar = true;
	}
}

static t_conv&	extractNaNorInf( std::string& literal, t_conv& conv )
{
	conv.isInvalidChar = true;
	conv.isInvalidInt = true;

	if (literal.compare("inf") == 0 || literal.compare("inff") == 0) {
		conv.isInf = true;
		if (conv.sign == 1) {
			conv.fpoint = std::numeric_limits<float>::infinity();
			conv.dpoint = std::numeric_limits<double>::infinity();
		}
		else {
			conv.fpoint = -std::numeric_limits<float>::infinity();
			conv.dpoint = -std::numeric_limits<double>::infinity();
		}
	}

	else if (literal.compare("nan") == 0 || literal.compare("nanf") == 0) {
		conv.isNan = true;
		conv.dpoint = std::numeric_limits<double>::quiet_NaN();
	}

	else
		throw std::invalid_argument("ERROR: Unsupported input.");

	return (conv);
}

static t_conv&	extractAsCharAndConvert( std::string& literal, t_conv& conv )
{
	conv.character = literal[0];
	conv.integer = static_cast<int>(conv.character);
	conv.dpoint = static_cast<double>(conv.character);
	conv.fpoint = static_cast<float>(conv.character);
	return (conv);
}

static t_conv&	extractAsFloatAndConvert( std::string& literal, t_conv& conv )
{
	if (literal.find(".") == std::string::npos)
		throw std::invalid_argument("ERROR: Missing period in float format.");

	try {
		conv.fpoint = std::atof(literal.c_str()) * conv.sign;
	}
	catch (const std::out_of_range& e) {
		throw std::invalid_argument("ERROR: Number out of range.");
	}

	conv.dpoint = static_cast<double>(conv.fpoint);
	conv.integer = static_cast<int>(conv.fpoint);
	conv.character = static_cast<char>(conv.fpoint);
	overflowCheck(conv);
	return (conv);
}

static t_conv&	extractAsDoubleAndConvert( std::string& literal, t_conv& conv )
{
	try {
		conv.dpoint = std::atof(literal.c_str()) * conv.sign;
	}
	catch (const std::out_of_range& e) {
		throw std::invalid_argument("ERROR: Number out of range.");
	}
	conv.integer = static_cast<int>(conv.dpoint);
	conv.fpoint = static_cast<float>(conv.dpoint);
	conv.character = static_cast<char>(conv.dpoint);
	overflowCheck(conv);
	return (conv);
}

static t_conv&	extractAsIntAndConvert( std::string& literal, t_conv& conv )
{
	long long	temp;

	try {
		temp = std::atoll(literal.c_str()) * conv.sign;
	}
	catch (const std::out_of_range& e) {
		throw std::invalid_argument("ERROR: Number out of range.");
	}
	if (temp > std::numeric_limits<int>::max()
		|| temp < std::numeric_limits<int>::min())
		throw std::invalid_argument("ERROR: Number out of range.");
	conv.integer = static_cast<int>(temp);
	conv.dpoint = static_cast<double>(conv.integer);
	conv.fpoint = static_cast<float>(conv.integer);
	conv.character =  static_cast<char>(conv.integer);
	overflowCheck(conv);
	return (conv);
}

t_conv		ScalarConverter::convert( std::string literal )
{
	t_conv	conv;
	memset(&conv, 0, sizeof(t_conv));
	conv.sign = 1;

	syntaxCheck(literal);

	if (!isdigit(literal[0])) {
		if (literal.length() == 1)
			return (extractAsCharAndConvert(literal, conv));
		else
			extractSign(literal, conv);
	}

	if (!isdigit(literal[0]))
		return (extractNaNorInf(literal, conv));

	else if (literal.find("f") != std::string::npos)
		return (extractAsFloatAndConvert(literal, conv));

	else if (literal.find(".") != std::string::npos)
		return (extractAsDoubleAndConvert(literal, conv));

	else
		return (extractAsIntAndConvert(literal, conv));
}
