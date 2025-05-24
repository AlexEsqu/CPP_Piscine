#ifndef CLASS_PRESIDENTIAL_PARDON_H
# define CLASS_PRESIDENTIAL_PARDON_H

# include "AForm.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat;

class PresidentialPardonForm: public AForm {

	private:

		std::string					_target;

	public:

		//----------------- CONSTRUCTORS ---------------------//

		PresidentialPardonForm( std::string target );

		//----------------- DESTRUCTOR -----------------------//

		~PresidentialPardonForm();

		//----------------- COPY CONSTRUCTORS ----------------//

		PresidentialPardonForm( const PresidentialPardonForm& original );

		//----------------- COPY ASSIGNEMENT -----------------//

		PresidentialPardonForm&		operator=( const PresidentialPardonForm& original );


		//----------------- MEMBER FUNCTIONS -----------------//

		void						execute( const Bureaucrat& executor ) const;

};

#endif
