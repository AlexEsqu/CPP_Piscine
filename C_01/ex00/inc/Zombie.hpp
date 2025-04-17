#ifndef ZOMBIE_CLASS_H
# define ZOMBIE_CLASS_H

# include <string>
# include <iostream>

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

class Zombie
{

public:

			Zombie( std::string name );
			~Zombie( void );
	void	announce( void ) const;

private:

	std::string _name;
	bool		_is_heap_allocated;

};

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

// Text coloring function I'd put in a separate header if it was allowed
// It actually uses leaving scope to reset color!
// Like so :
// {
// 	ColorSetter c(std::cout, ColorCode::RED);
// 	std::cout << "Toast" << std::endl;
// }

// enum ColorCode {
// 	RED		= 31,
// 	GREEN	= 32,
// 	BLUE	= 33,
// 	DEFAULT	= 39,
// };

// class ColorSetter
// {
// public:
// 	ColorSetter(std::ostream& os, ColorCode cc) : _os(os) { _os << "\033[" << (int)cc << "m"; }
// 	~ColorSetter() { _os << "\033[0m"; }
// private:
// 	std::ostream& _os;
// };


#endif
