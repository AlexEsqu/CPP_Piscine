#include <iostream>
#include <string>
#include <fstream>

enum sed_argv {
	PROG_NAME	= 0,
	FILENAME	= 1,
	TO_REPLACE	= 2,
	REPLACEMENT	= 3,
};

bool	is_bad_syntax( int argc)
{
	if (argc != 4)
	{
		std::cout << "USAGE : <filename>, <string to replace>, <string replacing>" << std::endl;
		return (true);
	}
	return (false);
}

void	replace_string_in_file ( std::ifstream& original,
	std::ofstream& modified, std::string& to_replace, std::string& replacement )
{
	std::string		line;
	while (!original.bad() && !original.fail() && !original.eof()) {
		std::getline(original, line);
		size_t	index_of_to_replace = line.find(to_replace);
		while (index_of_to_replace != std::string::npos) {

			line.erase(index_of_to_replace, to_replace.size());
			line.insert(index_of_to_replace, replacement);
			index_of_to_replace = line.find(to_replace, index_of_to_replace + replacement.length());
		}
		modified << line;
		if (!original.eof())
			modified << std::endl;
	}

}

int	main( int argc, char **argv ) {

	if (is_bad_syntax(argc))
		return (1);

	std::string		to_replace(argv[TO_REPLACE]);
	std::string		replacement(argv[REPLACEMENT]);
	std::string		filepath(argv[FILENAME]);

	std::ifstream	original(filepath.c_str());
	if (!original.is_open()) {
		std::cout << "Could not open the original file " << filepath << std::endl;
		return (1);
	}

	std::ofstream modified(filepath.append(".replace").c_str(), std::ios::trunc);
	if (!modified.is_open()) {
		std::cout << "Could not open the replacement file " << filepath << std::endl;
		return (1);
	}

	replace_string_in_file(original, modified, to_replace, replacement);

	original.close();
	modified.close();
	return (0);
}



