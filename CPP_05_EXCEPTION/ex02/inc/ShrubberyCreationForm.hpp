#ifndef CLASS_SHRUBERRY_CREATION_H
# define CLASS_SHRUBERRY_CREATION_H

# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include <fstream>

class Bureaucrat;

class ShrubberyCreationForm: public AForm {

	private:

		std::string					_target;
		static const std::string	_forest;

	public:

		//----------------- CONSTRUCTORS ---------------------//

		ShrubberyCreationForm( std::string target );

		//----------------- DESTRUCTOR -----------------------//

		~ShrubberyCreationForm();

		//----------------- COPY CONSTRUCTORS ----------------//

		ShrubberyCreationForm( const ShrubberyCreationForm& original );

		//----------------- COPY ASSIGNEMENT -----------------//

		ShrubberyCreationForm&		operator=( const ShrubberyCreationForm& original );


		//----------------- MEMBER FUNCTIONS -----------------//

		void						execute( const Bureaucrat& signator ) const;

};

#endif
