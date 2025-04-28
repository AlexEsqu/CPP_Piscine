#ifndef CLASS_ROBOTOMY_REQUEST_H
# define CLASS_ROBOTOMY_REQUEST_H

# include "AForm.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat;

class RobotomyRequestForm: public AForm {

	private:

		std::string					_target;

	public:

		//----------------- CONSTRUCTORS ---------------------//

		RobotomyRequestForm( std::string target );

		//----------------- DESTRUCTOR -----------------------//

		~RobotomyRequestForm();

		//----------------- COPY CONSTRUCTORS ----------------//

		RobotomyRequestForm( const RobotomyRequestForm& original );

		//----------------- COPY ASSIGNEMENT -----------------//

		RobotomyRequestForm&		operator=( const RobotomyRequestForm& original );


		//----------------- MEMBER FUNCTIONS -----------------//

		void						execute( const Bureaucrat& signator );

};

#endif
