#ifndef DATE_CLASS_H
# define DATE_CLASS_H

# include <string>
# include <iostream>
# include <iomanip>
# include <fstream>
# include <cstdlib>

// DATE SUBCLASS to do automatic map comparison (and for practice tbh)
class Date {
public:

	// Canonical form

	Date(std::string date);
	Date(const Date& original);
	~Date();
	Date&	operator=(const Date& original);

	// Operator overloads

	bool	operator==(const Date& comp) const;
	bool	operator>(const Date& comp) const;
	bool	operator>=(const Date& comp) const;
	bool	operator<(const Date& comp) const;
	bool	operator<=(const Date& comp) const;

	// getters

	int		getday() const;
	int		getmonth() const;
	int		getyear() const;
	bool	isItValid() const;

	// validator

	static bool		isValidDateValue(Date& date);
	static bool		isAfterBTCStart(Date& date);
	static bool		isLeapYear(int year);

private:
	int		day;
	int		month;
	int		year;
	bool	isValid;

};

std::ostream& operator<< (std::ostream& stream, const Date& date);


#endif
