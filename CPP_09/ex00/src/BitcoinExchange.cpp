#include "BitcoinExchange.hpp"

// ****************************************************************************#
//		BTC																	   #
// ****************************************************************************#

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
//		DATE																   #
// ****************************************************************************#

//----------------- DATE CLASS -----------------//

BTC::Date::Date(std::string date)
{
	#ifdef DEBUG
	//std::cout << "Calling Date constructor" << std::endl;
	#endif

	year = std::atoi(date.substr(0, 4).c_str());
	month = std::atoi(date.substr(5, 7).c_str());
	day = std::atoi(date.substr(8, 10).c_str());
	isValid = BTC::isValidDateValue(*this);
}

//----------------- DESTRUCTOR -----------------------//
BTC::Date::~Date()
{
	#ifdef DEBUG
	//std::cout << "Calling Date destructor" << std::endl;
	#endif
}

//----------------- COPY CONSTRUCTORS ----------------//
BTC::Date::Date( const Date& original )
{
	#ifdef DEBUG
	//std::cout << "Calling Date copy constructor" << std::endl;
	#endif

	*this = original;
}

//----------------- COPY ASSIGNEMENT -----------------//
BTC::Date&		BTC::Date::operator=( const Date& original )
{
	#ifdef DEBUG
	//std::cout << "Calling Date copy assignment" << std::endl;
	#endif

	if (this != &original) {
		day = original.getday();
		month = original.getmonth();
		year = original.getyear();
	}

	return (*this);
}

bool 		BTC::Date::operator==(const Date& comp) const
{
	return (year == comp.year && month == comp.month && day == comp.day);
}

bool		BTC::Date::operator>(const Date& comp) const
{
	if (year != comp.year)
		return (year > comp.year);
	if (month != comp.month)
		return (month > comp.month);
	return (day > comp.day);
}

bool		BTC::Date::operator>=(const Date& comp) const
{
	return (*this > comp || *this == comp);
}

bool		BTC::Date::operator<(const Date& comp) const
{
	if (year != comp.year)
		return (year < comp.year);
	if (month != comp.month)
		return (month < comp.month);
	return (day < comp.day);
}

bool		BTC::Date::operator<=(const Date& comp) const
{
	return (*this < comp || *this == comp);
}

int BTC::Date::getday() const
{
	return (day);
}

int BTC::Date::getmonth() const
{
	return (month);
}

int BTC::Date::getyear() const
{
	return (year);
}

bool	BTC::Date::isItValid() const
{
	return (isValid);
}

std::ostream& operator<< (std::ostream& stream, const BTC::Date& date)
{
	// Adding leading zeros to get 01-08-0054 instead of 1-8-54
	stream << std::setw(4) << std::setfill('0') << date.getyear() << "-";
	stream << std::setw(2) << std::setfill('0') << date.getmonth() << "-";
	stream << std::setw(2) << std::setfill('0') << date.getday();
	return (stream);
}

// ****************************************************************************#
//		MEMBER FUNCTION														   #
// ****************************************************************************#

//----------------- VALIDATING INPUT ----------------------------------------//

bool			BTC::isLeapYear(int year) {
    return (year % 4 == 0) && ( (year % 100 != 0) || (year % 400 == 0) );
}

// Check the value of a date struct are in the calendar
bool			BTC::isValidDateValue(Date& date)
{
	// Given the scope of the program, year can only be between 0 and 2500
	if (date.getyear() < 0 || date.getyear() > 2500)
		return (false);

	// Months can only be between 1 and 12
	if (date.getmonth() < 0 || date.getmonth() > 12)
		return (false);

	// February days only go to 28 OR 29 if bissextile year
	if (date.getmonth() == 2) {
		if (isLeapYear(date.getyear()) && date.getday() > 29)
			return (false);
		else if (date.getday() > 28)
			return (false);
	}

	// January, March, April, July, August, October and December can have 31 days
	else if (date.getmonth() == 1 || date.getmonth() == 3 || date.getmonth() == 5
		|| date.getmonth() == 7 || date.getmonth() == 8 || date.getmonth() == 10
		|| date.getmonth() == 12 ) {
		if (date.getday() > 31)
			return (false);
	}

	// The other only go up to 30 days
	else {
		if (date.getday() > 30)
			return (false);
	}

	return (true);
}

// Check if a string is in the YYYY-MM-DD format
bool			BTC::isValidDateFormat(std::string date)
{
	// std::cout << "Date " << date << " has len " << date.length() << "\n";

	// A valid date has precisely 10 chararacters
	if (date.length() != 10)
		return (false);

	// A valid date can only contain '-' or digit
	for (std::string::iterator it = date.begin(); it != date.end(); ++it)
	{
		if (!isdigit(*it) && *it != '-')
			return (false);
	}

	// std::cout << "Valid date: " << date << "\n";

	return (true);
}

// checks if a line in the provided database is in valid format
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

// to avoid loading the database if an input file is not provided, checks
// if input file actually exist and can be read
void	BTC::checkInputFile(std::string InputPath)
{
	#ifdef DEBUG
	std::cout << "Checking Input File" << std::endl;
	#endif

	if (access( InputPath.c_str(), F_OK ) == -1) {
		throw open_failed("Error: Input file at " + InputPath + " does not exist");
	}

	if (access( InputPath.c_str(), R_OK ) == -1) {
		throw open_failed("Error: Input file at " + InputPath + " cannot be read");
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
		throw BTC::open_failed("Failed to open the Database at " + _DBPath);
	}

	std::string	line;
	while (std::getline(dataBase, line)) {
		addLineToMap(line);
	}

	dataBase.close();
}

//----------------- CONVERTING INPUT ----------------------------------------//

// checks if a line in the provided input file is in valid format
void	BTC::printInputLineConversion(std::string line)
{
	// A valid line has minimum 14 char : 10 char date + ' ' + '|' + ' ' + value
	if (line.length() < 14 || line[10] != ' ' || line[11] != '|' || line[12] != ' ') {
		std::cout << "Error: bad input => " << line << std::endl;
		return;
	}

	// A valid date format of YYYY-MM-DD is always 10 character long
	std::string	dateStr = line.substr(0, 10);
	if (!isValidDateFormat(dateStr)) {
		std::cout << "Error: bad input => " << dateStr << std::endl;
		return;
	}

	// A valid date must be possible in our calendar (no 31 of february...)
	Date	date(dateStr);
	if (!date.isItValid()) {
		std::cout << "Error: invalid date => " << dateStr << std::endl;
		return;
	}

	std::string	value = line.substr(13);
	for (std::string::iterator it = value.begin(); it != value.end(); ++it) {
		// A valid value cannot be negative
		if (it == value.begin() && *it == '-'){
			std::cout << "Error: not a positive number. " << std::endl;
			return;
		}
		// A valid value contains only '.' or digits
		if (!isdigit(*it) && *it != '.') {
			std::cout << "Error: bad input => " << value << std::endl;
			return;
		}
	}

	// A valid value's goes from 1 to 1000, so it cannot hold more than 4 char
	// before the decimal point
	size_t decimalPoint = value.find('.');
	if (value.substr(0, decimalPoint).length() > 4) {
		std::cout << "Error: too large a number." << std::endl;
		return;
	}

	// A valid value's cannot be higher than 1000
	double	btcAmount = std::atof(value.c_str());
	if (btcAmount > 1000) {
		std::cout << "Error: too large a number." << std::endl;
		return;
	}



	// Look up the exact date in the database
	// DO NOT check for _database[date] as it will add a map item with value 0 ><
	double	btcValue = 0.0;
	std::map<Date, double>::iterator exactDate = _database.find(date);
	if (exactDate != _database.end()) {
		btcValue =  exactDate->second;
	}

	// IF the date does not exist, finds the smallest bigger date,
	else {
		std::map<Date, double>::iterator it = _database.upper_bound(date);

		// decrement to the biggest smaller date to use as btcValue
		if (--it != _database.begin()) {
			btcValue = it->second;
		}
		// Or return an error if no preceding date exist
		else {
			std::cout << "Error: No BTC conversion found." << std::endl;
			return;
		}
	}

	double	convertedDollarValue = btcAmount * btcValue;
	std::cout << date << " => " << value << " = ";
	std::cout << convertedDollarValue << "\n";

}

void			BTC::convertInputWithDB()
{
	std::ifstream inputFile(_inputPath);
	if (!inputFile.is_open()) {
		throw BTC::open_failed("Failed to open the Database at " + _DBPath);
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

const char* BTC::invalid_date::what() const throw()
{
	return ("ERROR: Date is invalid");
}

BTC::open_failed::open_failed(const std::string& msg) throw()
	: _error_message(msg)
{

}

const char* BTC::open_failed::what() const throw()
{
	return (_error_message.c_str());
}


