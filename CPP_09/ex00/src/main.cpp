#include "BitcoinExchange.hpp"

bool	isValidSyntaxAndInput(int argc)
{
	if (argc != 2) {
		std::cerr << "Usage is : <Binary> <Input file to evaluates>\n";
		return (false);
	}
	return (true);
}

int main(int argc, char** argv)
{
	// Checks syntax of <binary> <input file> and if input file can be opened
	if (!isValidSyntaxAndInput(argc))
		return (1);

	try {

		// Constructor loads data into a map, open input file
		BTC	btc(DATABASE_PATH, argv[1]);

		// Read input line by line, match valid with value / invalid with error
		btc.convertInputWithDB();

	}

	catch ( std::exception& e ){
		std::cerr << e.what() << std::endl;
		return (1);
	}

	return (0);

}
