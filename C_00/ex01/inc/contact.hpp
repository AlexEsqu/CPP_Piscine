#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

class Contact
{
public:
					Contact( void );
					Contact(int index,
						std::string firstName,
						std::string phonenumber,
						std::string nickName,
						std::string lastName,
						std::string darkestSecret);
					~Contact ( void );
	void			display ( void ) const;
	void			summarize ( void ) const;

private:
	int				_index;
	std::string		_darkestSecret;
	std::string		_phonenumber;
	std::string		_nickName;
	std::string		_lastName;
	std::string		_firstName;
};

#endif
