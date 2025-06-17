#ifndef BITCOIN_ECHANGE_H
# define BITCOIN_ECHANGE_H

# include <iostream>
# include <cstdlib>
# include <fstream>
# include <string>
# include <map>

# define DATABASE_PATH "data.csv"

// CLASS WITH MAP
class BTC {

public:

	// DATE SUBCLASS to do comparison (and for practice tbh)

	class Date {
	public:
		Date(std::string);
		Date(const Date& original);
		~Date();
		Date&	operator=(const Date& original);
		bool	operator==(const Date& comp) const;
		bool	operator>(const Date& comp) const;
		bool	operator>=(const Date& comp) const;
		bool	operator<(const Date& comp) const;
		bool	operator<=(const Date& comp) const;
		int		getday() const;
		int		getmonth() const;
		int		getyear() const;
		bool	isItValid() const;

	private:
		int		day;
		int		month;
		int		year;
		bool	isValid;

	};

	//CANONICAL FORM CUZ WE'RE FORCED TO

	BTC();
	~BTC();
	BTC(const BTC& original);
	BTC&		operator=(const BTC& original);

	// ESSENTIAL MEMBER FUNCTIONS

	void		addLineToMap(std::string line);
	void		loadDatabase();

	// VALIDATION

	static bool	isValidDateValue(Date& date);
	static bool	isValidDateFormat(std::string date);
	static bool	isValidDBLine(std::string line);

	// EXCEPTIONS

	class invalid_date : public std::exception {
	public :
			const char* what() const throw();
	};

	class open_failed : public std::exception {
	public :
			const char* what() const throw();
	};

private:

	std::map<Date, int>	_database;

};




// LOADING DATA.csv


// DATE VALIDATOR
// Valid date will always be in format Year-Month-Day


// VALUE VALIDATOR
// Valid value must be either a float or positive integer



#endif
