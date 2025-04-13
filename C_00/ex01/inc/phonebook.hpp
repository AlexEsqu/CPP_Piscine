#include "contact.hpp"

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

# define MAX_CONTACT 8

class Phonebook
{
public:
				Phonebook( void );
				~Phonebook( void );
	void		add( void );
	void		search( void ) const;
	void		display( int index ) const;

private:
	Contact		_contactArray[8];
	int			_currently_filled;
	int			_index_to_be_filled;

	bool		is_valid_search_query(std::string query) const;
	void		summarize( void ) const;
};


#endif
