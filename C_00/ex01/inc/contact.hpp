#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

class Contact
{
public:
	std::string	index;
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phonenumber;
	std::string	darkestSecret;

				Contact ( void );
				~Contact ( void );

	std::string	Prompt( std::string prompt );
	void		Fill( void );
};

#endif
