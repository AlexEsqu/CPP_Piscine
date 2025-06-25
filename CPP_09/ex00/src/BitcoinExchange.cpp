#include "BitcoinExchange.hpp"

// ****************************************************************************#
//		BTC																	   #
// ****************************************************************************#

const Date		BTC::_BTCStart("2009-01-09");

//----------------- CONSTRUCTORS ---------------------//

BTC::BTC(std::string DBPath, char* inputFile)
	: _inputPath(inputFile)
	, _DBPath(DBPath)
	, _database(std::map<Date, double>())
{
	#ifdef DEBUG
	std::cout << "Calling BTC constructor" << std::endl;
	#endif

	checkInputFile(_inputPath);
	loadDatabase(_DBPath);

}

//----------------- DESTRUCTOR -----------------------//
BTC::~BTC()
{
	#ifdef DEBUG
	std::cout << "Calling BTC destructor" << std::endl;
	#endif
}

//----------------- COPY CONSTRUCTORS ----------------//
BTC::BTC( const BTC& original )
	: _inputPath(original._inputPath)
	, _DBPath(original._DBPath)
	, _database(std::map<Date, double>())
{
	#ifdef DEBUG
	std::cout << "Calling BTC copy constructor" << std::endl;
	#endif

	checkInputFile(_inputPath);
	loadDatabase(_DBPath);

}

//----------------- COPY ASSIGNEMENT -----------------//
BTC&			BTC::operator=( const BTC& original )
{
	#ifdef DEBUG
	std::cout << "Calling BTC copy assignment" << std::endl;
	#endif

	if (this == &original)
		return *this;

	checkInputFile(_inputPath);
	loadDatabase(_DBPath);

	return *this;
}

// ****************************************************************************#
//		MEMBER FUNCTION														   #
// ****************************************************************************#

//----------------- VALIDATING INPUT ----------------------------------------//

// Check if a string is in the YYYY-MM-DD format
bool			BTC::isValidDateFormat(std::string date)
{
	// A valid date has precisely 10 chararacters
	if (date.length() != 10)
		return (false);

	// A valid date can only contain '-' or digit
	for (std::string::iterator it = date.begin(); it != date.end(); ++it)
	{
		if (!isdigit(*it) && *it != '-')
			return (false);
	}

	return (true);
}

// Checks if a line in the provided database is in valid format
bool			BTC::isValidDBLine(std::string line)
{
	// A valid line has minimum 12 char : 10 char date + ',' + value
	if (line.length() < 12 || line[10] != ',')
		return (false);

	// A valid date format of YYYY-MM-DD is always 10 character long
	std::string	dateStr = line.substr(0, 10);
	if (!isValidDateFormat(dateStr))
		return (false);

	// A valid conversion rate contains '.' or digits
	std::string	value = line.substr(11);
	for (std::string::iterator it = value.begin(); it != value.end(); ++it)
	{
		if (!isdigit(*it) && *it != '.')
			return (false);
	}

	return (true);
}

// check the date provided could believably have a conversion value
// Bitcoin has first traded on the 9th January 2009
bool			BTC::isAfterBTCStart(Date& date)
{
	return (date >= BTC::_BTCStart);
}

// to avoid loading the database if an input file is not provided, checks
// if input file actually exist and can be read
void	BTC::checkInputFile(std::string InputPath)
{
	#ifdef DEBUG
	std::cout << "Checking Input File" << std::endl;
	#endif

	if (access( InputPath.c_str(), F_OK ) == -1) {
		throw open_failed();
	}

	if (access( InputPath.c_str(), R_OK ) == -1) {
		throw open_failed();
	}
}

//----------------- LOADING DATABASE ----------------------------------------//

// Add valid lines to the database, ignores invalid lines
void			BTC::addLineToMap(std::string line)
{
	// Checking syntax and discarding if invalid
	if (!isValidDBLine(line))
		return;

	// Extracts and splitting the date into a Date class
	Date	date = Date(line.substr(0, 10));
	// Database has no need to hold invalid dates so discards if invalid
	if (!date.isItValid())
		return;

	// Extracts the conversion rate into a floating point double
	double	conv_rate = std::atof(line.substr(11).c_str());

	_database[date] = conv_rate;

	#ifdef DEBUG
	//std::cout << "DATABASE [" << date << "] = " << _database[date] << "\n";
	#endif

}

void	BTC::loadDatabase(std::string DatabasePath)
{
	#ifdef DEBUG
	std::cout << "Loading database" << std::endl;
	#endif

	std::ifstream dataBase(DatabasePath.c_str());
	if (!dataBase.is_open()) {
		throw BTC::open_failed();
	}

	std::string	line;
	while (std::getline(dataBase, line)) {
		addLineToMap(line);
	}

	dataBase.close();
}

//----------------- CONVERTING INPUT ----------------------------------------//

Date	BTC::extractValidDate(std::string& inputLine)
{
	// A valid line has minimum 14 char : 10 char date + ' ' + '|' + ' ' + value
	if (inputLine.length() < 14 || inputLine[10] != ' '
		|| inputLine[11] != '|' || inputLine[12] != ' ') {
		throw BTC::bad_input(inputLine);
	}

	// A valid date format of YYYY-MM-DD is always 10 character long
	std::string	dateStr = inputLine.substr(0, 10);

	// checks if date is in the correct format
	if (!isValidDateFormat(dateStr)) {
		throw BTC::bad_input(dateStr);
	}

	// extract into a Date class object and checks if exists in calendar
	Date	date(dateStr);
	if (!date.isItValid() || !isAfterBTCStart(date)) {
		throw BTC::bad_input(dateStr);
	}

	return (date);
}

double	BTC::extractBTCAmount(std::string& inputLine)
{
	std::string	value = inputLine.substr(13);
	// Iterates over the value part of the string to check its syntax
	for (std::string::iterator it = value.begin(); it != value.end(); ++it) {
		// A valid value cannot be negative
		if (it == value.begin() && *it == '-'){
			throw no_negative();
		}
		// A valid value contains only '.' or digits
		if (!isdigit(*it) && *it != '.') {
			throw bad_input(value);
		}
	}

	// A valid value is 1 to 1000, so it cannot hold more than 4 char before .
	size_t decimalPoint = value.find('.');
	if (value.substr(0, decimalPoint).length() > 4) {
		throw too_big();
	}
	// A valid value's cannot be higher than 1000
	double	btcAmount = std::atof(value.c_str());
	if (btcAmount > 1000) {
		throw too_big();
	}

	return (btcAmount);
}

double	BTC::extractBTCValue(Date& date)
{
	double	btcValue = 0.0;

	// Look up the exact date in the database
	// DO NOT check for _database[date] as it will add a map item with value 0 ><
	std::map<Date, double>::iterator exactDate = _database.find(date);
	if (exactDate != _database.end()) {
		btcValue =  exactDate->second;
	}

	// If the date does not exist, finds the smallest bigger date,
	else {
		std::map<Date, double>::iterator it = _database.upper_bound(date);

		// decrement to the biggest smaller date to use as btcValue
		if (--it != _database.begin()) {
			btcValue = it->second;
		}

		// Or return an error if no preceding date exist
		else {
			throw too_old();
		}
	}

	return (btcValue);
}

// prints out either error message or BTC conversion based on database
void	BTC::printInputLineConversion(std::string line)
{
	try
	{
		Date	date = extractValidDate(line);
		double	btcAmount = extractBTCAmount(line);
		double	btcValue = extractBTCValue(date);

		double	convertedDollarValue = btcAmount * btcValue;

		// Formatting the output
		std::cout << date << " => " << btcAmount << " = ";
		// Ensuring two decimal values after the comma since price ($1.00)
		std::cout << std::fixed << std::setprecision(2);
		std::cout << convertedDollarValue << "\n";
	}

	catch (std::exception& e)
	{
		std::cout << e.what() << "\n";
	}
}

void			BTC::convertInputWithDB()
{
	std::ifstream inputFile(_inputPath);
	if (!inputFile.is_open()) {
		throw BTC::open_failed();
	}

	std::string	line;
	std::getline(inputFile, line); // skipping the header line
	while (std::getline(inputFile, line)) {
		#ifdef DEBUG
		std::cout << line << " converts to ";
		#endif
		printInputLineConversion(line);
	}
}

// ****************************************************************************#
//		EXCEPTION															   #
// ****************************************************************************#


BTC::bad_input::bad_input(const std::string& msg) throw()
	: _error_message(static_cast<std::string>("Error: bad input => ").append(msg))
{

}

const char* BTC::bad_input::what() const throw()
{
	return (_error_message.c_str());
}

const char* BTC::open_failed::what() const throw()
{
	return ("Error: could not open file.");
}

const char* BTC::no_negative::what() const throw()
{
	return ("Error: not a positive number.");
}

const char* BTC::too_big::what() const throw()
{
	return ("Error: too large a number.");
}

const char* BTC::too_old::what() const throw()
{
	return ("Error: No corresponding value in database.");
}
