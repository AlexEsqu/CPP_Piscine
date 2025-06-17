#include "BitcoinExchange.hpp"

int main(int argc, char** )
{
	if (argc != 2) {
		std::cout << "Usage is : <binary> <file containing the dates to evaluates>\n";
		return (1);
	}

	// loading data into a map
	try { BTC	btc; }
	catch ( std::exception& e ){
		std::cerr << e.what() << std::endl;
	}

	// reading input

	// checking if valid input

	// match valid input


	// create file
	// input in file data or error

	return (0);

}
