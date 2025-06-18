#ifndef BITCOIN_ECHANGE_H
# define BITCOIN_ECHANGE_H

# include <iostream>
# include <iomanip>
# include <cstdlib>
# include <fstream>
# include <string>
# include <map>
# include <unistd.h>

# define DATABASE_PATH "data.csv"

// CLASS WITH MAP
class BTC {

public:

	// DATE SUBCLASS to do comparison (and for practice tbh)
	class Date {
	public:
		Date(std::string date);
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

	//CANONICAL FORM CUZ WE HAVE TO

	BTC(std::string  DBPath, char* inputPath);
	~BTC();
	BTC(const BTC& original);
	BTC&			operator=(const BTC& original);

	// CORE MEMBER FUNCTIONS

	void			checkInputFile(std::string inputPath);
	void			addLineToMap(std::string line);
	void			loadDatabase(std::string DBPath);
	void			convertInputWithDB();
	void			printInputLineConversion(std::string line);

	// VALIDATION

	static bool		isValidDateValue(Date& date);
	static bool		isValidDateFormat(std::string date);
	static bool		isValidDBLine(std::string line);

	// EXCEPTIONS

	class invalid_date : public std::exception {
	public :

		const char* what() const throw();
	};

	// throw() is a runtime check ensuring the function does not throw.
	// It has nothing to do with the throw keyword throwing exception.
	// It´s deprecated, so if 42 wasn´t a stick in the mud I'd have used
	// noexcept, which checks at compilation instead
	class open_failed : public std::exception {
	public :
		open_failed(const std::string& msg) throw();
		~open_failed() throw() {};
		const char* what() const throw();
	private:
		std::string	_error_message;
	};

private:

	char*					_inputPath;
	std::string				_DBPath;
	std::map<Date, double>	_database;

};

std::ostream& operator<< (std::ostream& stream, const BTC::Date& date);




// LOADING DATA.csv





// VALUE VALIDATOR
// Valid value must be either a float or positive integer



#endif
