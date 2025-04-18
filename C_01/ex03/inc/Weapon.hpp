#ifndef WEAPON_CLASS_H
# define WEAPON_CLASS_H

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

class Weapon
{
public:
						Weapon( std::string name );
						~Weapon( void );
	const std::string&	getType( void ) const;
	void				setType( std::string type );

private:
	std::string			_type;

};

#endif
