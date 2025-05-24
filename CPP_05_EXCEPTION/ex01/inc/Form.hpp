#ifndef CLASS_FORM_H
# define CLASS_FORM_H

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

	private:

		const std::string	_name;
		const int			_gradeToSign;
		const int			_gradeToExec;
		bool				_isSigned;


	public:

	//----------------- CONSTRUCTORS ---------------------//

						Form( const std::string name, int grade_to_sign, int grade_to_exec );

	//----------------- DESTRUCTOR -----------------------//

						~Form();

	//----------------- COPY CONSTRUCTORS ----------------//

						Form( const Form& original );

	//----------------- COPY ASSIGNEMENT -----------------//

	Form&				operator=( const Form& original );


	//----------------- MEMBER FUNCTIONS -----------------//

	const std::string	getName() const;
	int					getGradeToSign() const;
	int					getGradeToExec() const;
	bool				getIfSigned() const;

	void				beSigned( Bureaucrat signator );

	//----------------- EXCEPTIONS ------------------------//

	class GradeTooLowException : public std::exception {
		public :
			const char* what() const throw();
	};

	class GradeTooHighException : public std::exception {
		public :
			const char* what() const throw();
	};

	class IsAlreadySigned : public std::exception {
		public :
			const char* what() const throw();
	};

};


std::ostream& operator<<( std::ostream& out, const Form& b );


#endif
