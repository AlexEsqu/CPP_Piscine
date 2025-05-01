#ifndef CLASS_SCALARCONVERTER_H
# define CLASS_SCALARCONVERTER_H

# include <iostream>
# include <string>

class	ScalarConverter
{
	public:

		static void			convert( std::string representation );

	private:

		ScalarConverter();
		~ScalarConverter();
		ScalarConverter( const ScalarConverter& original );
		ScalarConverter&	operator=( const ScalarConverter& original );

		struct	representation {
			int		integer;
			char	character;
			float	fpoint;
			double	dpoint;
		};

}


#endif
