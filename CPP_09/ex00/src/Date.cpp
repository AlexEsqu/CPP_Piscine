#include "Date.hpp"

// ****************************************************************************#
//		DATE																   #
// ****************************************************************************#

//----------------- DATE CLASS -----------------//

Date::Date(std::string date)
{
	#ifdef DEBUG
	//std::cout << "Calling Date constructor" << std::endl;
	#endif

	year = std::atoi(date.substr(0, 4).c_str());
	month = std::atoi(date.substr(5, 7).c_str());
	day = std::atoi(date.substr(8, 10).c_str());
	isValid = isValidDateValue(*this);
}

//----------------- DESTRUCTOR -----------------------//
Date::~Date()
{
	#ifdef DEBUG
	//std::cout << "Calling Date destructor" << std::endl;
	#endif
}

//----------------- COPY CONSTRUCTORS ----------------//
Date::Date( const Date& original )
{
	#ifdef DEBUG
	//std::cout << "Calling Date copy constructor" << std::endl;
	#endif

	*this = original;
}

//----------------- COPY ASSIGNEMENT -----------------//
Date&		Date::operator=( const Date& original )
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

// ****************************************************************************#
//		COMPARISON OPERATORS												   #
// ****************************************************************************#

bool 		Date::operator==(const Date& comp) const
{
	return (year == comp.year && month == comp.month && day == comp.day);
}

bool		Date::operator>(const Date& comp) const
{
	if (year != comp.year)
		return (year > comp.year);
	if (month != comp.month)
		return (month > comp.month);
	return (day > comp.day);
}

bool		Date::operator>=(const Date& comp) const
{
	return (*this > comp || *this == comp);
}

bool		Date::operator<(const Date& comp) const
{
	if (year != comp.year)
		return (year < comp.year);
	if (month != comp.month)
		return (month < comp.month);
	return (day < comp.day);
}

bool		Date::operator<=(const Date& comp) const
{
	return (*this < comp || *this == comp);
}

// ****************************************************************************#
//		REPRESENTATION														   #
// ****************************************************************************#

std::ostream& operator<< (std::ostream& stream, const Date& date)
{
	// Adding leading zeros to get 01-08-0054 instead of 1-8-54
	stream << std::setw(4) << std::setfill('0') << date.getyear() << "-";
	stream << std::setw(2) << std::setfill('0') << date.getmonth() << "-";
	stream << std::setw(2) << std::setfill('0') << date.getday();
	return (stream);
}

// ****************************************************************************#
//		GETTERS																   #
// ****************************************************************************#

int Date::getday() const
{
	return (day);
}

int Date::getmonth() const
{
	return (month);
}

int Date::getyear() const
{
	return (year);
}

bool	Date::isItValid() const
{
	return (isValid);
}

// ****************************************************************************#
//		DATE VALIDATION														   #
// ****************************************************************************#

bool			Date::isLeapYear(int year)
{
    return (year % 4 == 0) && ( (year % 100 != 0) || (year % 400 == 0) );
}

// Check the value of a date struct are in the calendar
bool			Date::isValidDateValue(Date& date)
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
