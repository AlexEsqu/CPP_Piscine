#ifndef CLASS_AFORM_H
# define CLASS_AFORM_H

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

private:

		const std::string	_name;
		const int			_gradeToSign;
		const int			_gradeToExec;
		bool				_isSigned;

public:

	//----------------- CONSTRUCTORS ---------------------//

						AForm( const std::string name, int grade_to_sign, int grade_to_exec );

	//----------------- DESTRUCTOR -----------------------//

	virtual				~AForm();

	//----------------- COPY CONSTRUCTORS ----------------//

						AForm( const AForm& original );

	//----------------- COPY ASSIGNEMENT -----------------//

	AForm&				operator=( const AForm& original );


	//----------------- MEMBER FUNCTIONS -----------------//

	const std::string	getName() const;
	int					getGradeToSign() const;
	int					getGradeToExec() const;
	bool				getIfSigned() const;
	void				setSigned( bool value );

	void				beSigned( Bureaucrat signator );
	virtual void		execute( const Bureaucrat& executor ) const = 0;

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

	class IsNotYetSigned : public std::exception {
		public :
			const char* what() const throw();
	};

};

std::ostream& operator<<( std::ostream& out, const AForm& b );

#endif
