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

	openInputFile(_inputPath);
	loadDatabase(_DBPath);

}

//----------------- DESTRUCTOR -----------------------//
BTC::~BTC()
{
	#ifdef DEBUG
	std::cout << "Calling BTC destructor" << std::endl;
	#endif

	delete _input;
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

	openInputFile(_inputPath);
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

	openInputFile(_inputPath);
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

	if (!BTC::isValidDateFormat(date))
		throw BTC::invalid_date();

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

// Check the value of a date struct are in the calendar
bool			BTC::isValidDateValue(Date& )
{


	// TO BE DONE



	return (true);
}

// Check if a string is in the YYYY-MM-DD format
bool			BTC::isValidDateFormat(std::string date)
{
	// A valid date has precisely 10 chararacters
	if (date.length() == 11)
		return (false);

	// A valid date can only contain '-' or digit
	for (std::string::iterator it = date.begin(); it != date.end(); ++it)
	{
		if (!isdigit(*it) && *it != '-')
			return (false);
	}

	return (true);
}

//----------------- LOADING DATABASE ----------------------------------------//

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

// Add valid lines to the database, ignores invalid lines
void			BTC::addLineToMap(std::string line)
{
	// Checking syntax and discarding if invalid
	if (!isValidDBLine(line))
		return;

	// Extracts and splitting the date into a Date class
	Date	date = Date(line.substr(0, 10));
	// Database has no need to hold invalid dates so discards the line
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

//----------------- LOADING INPUT FILE ----------------------------------------//

std::ifstream*	BTC::openInputFile(char* inputFilePath)
{
	#ifdef DEBUG
	std::cout << "Opening Input File" << std::endl;
	#endif

	if (access( inputFilePath, F_OK ) == -1) {
		std::cerr << "Input File does not exist\n";
		throw open_failed();
	}

	if (access( inputFilePath, R_OK ) == -1) {
		std::cerr << "Input File cannot be read\n";
		throw open_failed();
	}

	std::ifstream*	input = new std::ifstream(inputFilePath);

	if (!input->is_open()) {
		delete input;
		throw open_failed();
	}

	return	input;
}



// ****************************************************************************#
//		EXCEPTION															   #
// ****************************************************************************#

const char* BTC::invalid_date::what() const throw()
{
	return ("ERROR: Date is invalid");
}

const char* BTC::open_failed::what() const throw()
{
	return ("ERROR: Failed to open the database");
}
