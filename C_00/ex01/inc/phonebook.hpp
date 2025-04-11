#include "contact.hpp"

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

class Phonebook
{
public:
	Contact contactArray[8];

	Phonebook ( void );
	~Phonebook ( void );

	void Add( void );
	void Search(void) const;
};


#endif
