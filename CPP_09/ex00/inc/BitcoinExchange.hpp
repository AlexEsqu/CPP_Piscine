#ifndef BITCOIN_ECHANGE_H
# define BITCOIN_ECHANGE_H

# include "Date.hpp"

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
	Date			extractValidDate(std::string& inputLine);
	double			extractBTCAmount(std::string& inputLine);
	double			extractBTCValue(Date& date);
	void			printInputLineConversion(std::string line);

	// VALIDATION

	static bool		isValidDateFormat(std::string date);
	static bool		isValidDBLine(std::string line);
	static bool		isAfterBTCStart(Date& date);

	// EXCEPTIONS

	class bad_input : public std::exception {
	public :
		bad_input(const std::string& msg) throw();
		~bad_input() throw() {};
		const char* what() const throw();
	private:
		std::string	_error_message;
	};

	class open_failed : public std::exception {
	public :
		const char* what() const throw();
	};

	class no_negative : public std::exception {
	public :
		const char* what() const throw();
	};

	class too_big : public std::exception {
	public :
		const char* what() const throw();
	};

	class too_old : public std::exception {
	public :
		const char* what() const throw();
	};


private:

	char*					_inputPath;
	std::string				_DBPath;
	std::map<Date, double>	_database;
	static const Date		_BTCStart;

};



#endif
