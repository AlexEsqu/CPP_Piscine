#ifndef CLASS_BUREAUCRAT_H
# define CLASS_BUREAUCRAT_H

# include <string>
# include <iostream>
# include <cstdlib>
# include <ctime>
# include "AForm.hpp"

class	AForm;

class Bureaucrat {

	private:

		const std::string	_name;
		int					_grade;

	public:

		//----------------- CONSTRUCTORS ---------------------//

							Bureaucrat( const std::string name, int grade );

		//----------------- DESTRUCTOR -----------------------//

							~Bureaucrat();

		//----------------- COPY CONSTRUCTORS ----------------//

							Bureaucrat( const Bureaucrat& original );

		//----------------- COPY ASSIGNEMENT -----------------//

		Bureaucrat&			operator=( const Bureaucrat& original );


		//----------------- MEMBER FUNCTIONS -----------------//

		const std::string	getName() const;
		int					getGrade() const;
		void				incrementGrade();
		void				decrementGrade();

		void				signForm( AForm& form );

		//----------------- EXCEPTIONS ------------------------//

		class GradeTooLowException : public std::exception {
			public :
				const char* what() const throw();
		};

		class GradeTooHighException : public std::exception {
			public :
				const char* what() const throw();
		};
};

std::ostream& operator<<( std::ostream& out, const Bureaucrat& b );


# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define STOP_COLOR "\033[0m"

# define FAINT "\033[2m"
# define BOLD "\033[1m"
# define STOP_STYLE "\033[22m"

# define ITALIC "\033[3m"
# define STOP_ITALIC "\033[23m"

# ifndef DEBUG
#  define DEBUG 0
# endif

#endif
