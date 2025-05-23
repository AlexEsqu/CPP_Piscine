#ifndef CLASS_SCALARCONVERTER_H
# define CLASS_SCALARCONVERTER_H

# include <iostream>
# include <string>
# include <cstdlib>
# include <iomanip>
# include <limits>
# include <format>
# include <cstring>

struct	t_conv {

	int			sign;

	bool		isInvalidInt;
	bool		isInvalidChar;
	bool		isInvalidFloat;

	bool		isInf;
	bool		isNan;

	char		character;
	int			integer;
	float		fpoint;
	double		dpoint;

};

class	ScalarConverter
{
	public:

		static t_conv		convert( std::string representation );

	private:

		ScalarConverter();
		~ScalarConverter();
		ScalarConverter( const ScalarConverter& original );
		ScalarConverter&	operator=( const ScalarConverter& original );

};

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define STOP_COLOR "\033[0m"

# define FAINT "\033[2m"
# define BOLD "\033[1m"
# define STOP_STYLE "\033[22m"

# define ITALIC "\033[3m"
# define STOP_ITALIC "\033[23m"

# ifndef DEBUG
#  define DEBUG 0
# endif


#endif
