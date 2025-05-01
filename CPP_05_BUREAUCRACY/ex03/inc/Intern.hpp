#ifndef CLASS_INTERN_H
# define CLASS_INTERN_H

# include <string>
# include <iostream>
# include <cstdlib>
# include <ctime>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class	AForm;

class 	Intern {

	private:

		static AForm	*_make_shrubbery(const std::string& target);
		static AForm	*_make_pardon(const std::string& target);
		static AForm	*_make_request(const std::string& target);

		struct FormMatch {
			std::string type;
			AForm* (*constructor)(const std::string& target);
		};

		FormMatch*	_formMatches;

	public:

		//----------------- CONSTRUCTORS ---------------------//

							Intern();

		//----------------- DESTRUCTOR -----------------------//

							~Intern();

		//----------------- COPY CONSTRUCTORS ----------------//

							Intern( const Intern& original );

		//----------------- COPY ASSIGNEMENT -----------------//

		Intern&				operator=( const Intern& original );


		//----------------- MEMBER FUNCTIONS -----------------//

		AForm*				makeForm( std::string formType, std::string target );

		//----------------- EXCEPTIONS ------------------------//

		class NonExistentForm : public std::exception {
			public :
				const char* what() const throw();
		};

};

#endif
