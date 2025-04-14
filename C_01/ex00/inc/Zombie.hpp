#ifndef ZOMBIE_CLASS_H
# define ZOMBIE_CLASS_H

# include <string>

class Zombie
{

public:

			Zombie( std::string name );
			~Zombie( void );
	void	announce( void ) const;
	Zombie*	newZombie( std::string name );
	void	randomChump( std::string name );

private:

	std::string _name;
	bool		_is_heap_allocated;

};

#endif
