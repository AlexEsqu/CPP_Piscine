#ifndef CLASS_SERIALIZE_H
# define CLASS_SERIALIZE_H

# include <iostream>
# include <stdint.h>
# include "Data.hpp"

class	Serializer
{
	public:

		static uintptr_t	serialize( Data* ptr );
		static Data*		deserialize( uintptr_t raw );

	private:

		Serializer();
		~Serializer();
		Serializer( const Serializer& original );
		Serializer&	operator=( const Serializer& original );

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
