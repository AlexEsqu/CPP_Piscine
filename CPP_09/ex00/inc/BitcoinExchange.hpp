#ifndef BITCOIN_ECHANGE_H
# define BITCOIN_ECHANGE_H

# include <iostream>
# include <map>

// STRUCT TO STORE DATES
struct Date {

	int	_day;
	int	_month;
	int	_year;

};

// FUNCTIONS TO COMPARE DATE STRUCTS



// CLASS WITH MAP
class BitcoinExchange {

	public:

		//CANONICAL FORM CUZ WE'RE FORCED TO 

		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& original);
		BitcoinExchange&	operator=(const BitcoinExchange& original);


	private:

		std::map<Date, int>	_database;





};




// LOADING DATA.csv


// DATE VALIDATOR
// Valid date will always be in format Year-Month-Day


// VALUE VALIDATOR
// Valid value must be either a float or positive integer



#endif
