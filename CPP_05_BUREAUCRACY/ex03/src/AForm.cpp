#include "AForm.hpp"

//----------------- CONSTRUCTORS ---------------------//

AForm::AForm( const std::string name, int gradeToSign, int gradeToExec )
	: _name(name)
	, _gradeToSign(gradeToSign)
	, _gradeToExec(gradeToExec)
	, _isSigned(false)
{
	if (DEBUG) {
		std::cout << GREEN << "[FORM] Calling Constructor for ";
		std::cout << *this << STOP_COLOR << std::endl;
	}

	if (_gradeToSign < 1 || _gradeToExec < 1) {
		if (DEBUG) {
			std::cout << RED << "[FORM] Invalid grade for ";
			std::cout << *this << STOP_COLOR << std::endl;
		}
		throw GradeTooHighException();
	}

	if (_gradeToSign > 150 || _gradeToExec > 150) {
		if (DEBUG) {
			std::cout << RED << "[FORM] Invalid grade for ";
			std::cout << *this << STOP_COLOR << std::endl;
		}
		throw GradeTooLowException();
	}
}

//----------------- DESTRUCTORS ---------------------//

AForm::~AForm()
{
	if (DEBUG) {
		std::cout << RED << "[FORM] Calling Destructor for ";
		std::cout << *this << STOP_COLOR << std::endl;
	}
}

//----------------- COPY CONSTRUCTORS ----------------//

AForm::AForm( const AForm& original )
	: _name(original.getName())
	, _gradeToSign(original.getGradeToSign())
	, _gradeToExec(original.getGradeToExec())
	, _isSigned(original.getIfSigned())
{
	if (DEBUG) {
		std::cout << GREEN << "[FORM] Calling Copy Constructor for ";
		std::cout << original << STOP_COLOR << std::endl;
	}
}

//----------------- COPY ASSIGNEMENT -----------------//

AForm&				AForm::operator=( const AForm& original )
{
	if (DEBUG) {
		std::cout << GREEN << "[FORM] Calling Copy Assignement for ";
		std::cout << *this << STOP_COLOR << std::endl;
	}

	if (this == &original)
		return *this;

	_isSigned = original.getIfSigned();

	// _name is const and cannot be modified
	// _gradeToSign = original.getGradeToSign();
	// _gradeToExec = original.getGradeToExec();

	return *this;
}


//----------------- MEMBER FUNCTION -----------------//

const std::string		AForm::getName() const
{
	return _name;
}

int						AForm::getGradeToSign() const
{
	return _gradeToSign;
}

int						AForm::getGradeToExec() const
{
	return _gradeToExec;
}

bool					AForm::getIfSigned() const
{
	return _isSigned;
}

void					AForm::setSigned( bool value )
{
	_isSigned = value;
}

void					AForm::beSigned( Bureaucrat signator )
{
	if (getGradeToSign() < signator.getGrade())
		throw GradeTooLowException();
	else if (getIfSigned())
		throw IsAlreadySigned();
	else
		setSigned(true);
}

//----------------- EXCEPTIONS ---------------------//

const char* AForm::GradeTooHighException::what() const throw()
{
	return "ERROR: Grade is too high !";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "ERROR: Grade is too low !";
}

const char* AForm::IsAlreadySigned::what() const throw()
{
	return "ERROR: Form is already signed.";
}

const char* AForm::IsNotYetSigned::what() const throw()
{
	return "ERROR: Form is not yet signed.";
}

//----------------- VISUALIZATION -----------------//

std::ostream& operator<<( std::ostream& out, const AForm& form )
{
	out << "Form " << form.getName() ;
	out << " [ Signature : " << form.getGradeToSign() << " ] ";
	out << " [ Execution : " << form.getGradeToExec() << " ] ";
	out << " [ Signed : ";
	if (!form.getIfSigned()) { out << "not "; }
	out << "signed ]";
	return (out);
}
