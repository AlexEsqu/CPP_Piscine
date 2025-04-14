#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

# include "contact.hpp"
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
	Contact		_contactArray[MAX_CONTACT];
	int			_currently_filled;
	int			_index_to_be_filled;

	bool		is_valid_search_query(std::string query) const;
	void		summarize( void ) const;
};

#endif
