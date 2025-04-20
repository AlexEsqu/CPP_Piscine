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


class Zombie
{

public:
			Zombie( void );
			Zombie( std::string name );
			~Zombie( void );
	void	announce( void ) const;
	void	setZombieName( std::string name );

private:

	std::string _name;

};

Zombie*	zombieHorde( int N, std::string name );


#endif
