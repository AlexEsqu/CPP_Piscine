#include "sedd.hpp"

enum sed_argv {
	PROG_NAME	= 0,
	FILENAME	= 1,
	TO_REPLACE	= 2,
	REPLACEMENT	= 3,
};

bool	is_bad_syntax( int argc) {
	if (argc != 4)
	{
		std::cout << "USAGE : <filename>, <string to replace>, <string replacing>" << std::endl;
		return (true);
	}
	return (false);
}

int	main( int argc, char **argv ) {

	if (is_bad_syntax(argc)) {
		return (1); }

	std::string		filepath = argv[FILENAME];
	std::ifstream	original(filepath.c_str());
	if (!original.is_open()) {
		std::cout << "Could not open the original file " << filepath << std::endl;
		return (1);
	}

	std::ofstream modified(filepath.append(".replace").c_str(), std::ios::trunc);
	if (!modified.is_open()) {
		std::cout << "Could not open the replacement file " << filepath << ".replacement" << std::endl;
		return (1);
	}

	std::string		to_replace = argv[TO_REPLACE];
	std::string		replacement = argv[REPLACEMENT];





	original.close();
	modified.close();
	return (0);
}



