#ifndef HARL_CLASS_H
# define HARL_CLASS_H

#include <iostream>

class Harl
{

private:
	void		debug( void );
	void		info( void );
	void		warning( void );
	void		error( void );

public:
				Harl( void );
				~Harl( void );
	void		complain( std::string level );
	void		(Harl::*actions[4])(void);
	std::string	levels[4];

};

#endif
