#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

class Contact
{
public:
					Contact( void );
					Contact(int index,
						std::string firstName,
						std::string lastName,
						std::string phonenumber,
						std::string nickName,
						std::string darkestSecret);
					~Contact ( void );
	void			display ( void ) const;
	void			summarize ( void ) const;

private:
	int				_index;
	std::string		_firstName;
	std::string		_lastName;
	std::string		_nickName;
	std::string		_phonenumber;
	std::string		_darkestSecret;
	std::string		resized_and_dotted( std::string string, int size ) const;
};

#endif


