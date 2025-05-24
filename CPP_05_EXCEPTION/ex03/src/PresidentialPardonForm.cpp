#include "PresidentialPardonForm.hpp"

//----------------- CONSTRUCTORS ---------------------//

PresidentialPardonForm::PresidentialPardonForm( std::string target )
	: AForm( "Presidential Pardon", 25, 5 )
	, _target(target)
{
	if (DEBUG) {
		std::cout << GREEN << "[PARDON] Calling Constructor for ";
		std::cout << *this << STOP_COLOR << std::endl;
	}
}

//----------------- DESTRUCTORS ---------------------//

PresidentialPardonForm::~PresidentialPardonForm()
{
	if (DEBUG) {
		std::cout << RED << "[PARDON] Calling Destructor for ";
		std::cout << *this << STOP_COLOR << std::endl;
	}
}

//----------------- COPY CONSTRUCTORS ----------------//

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& original )
	: AForm(original)
{
	if (DEBUG) {
		std::cout << GREEN << "[PARDON] Calling Copy Constructor for ";
		std::cout << original << STOP_COLOR << std::endl;
	}
}

//----------------- COPY ASSIGNEMENT -----------------//

PresidentialPardonForm&	PresidentialPardonForm::operator=( const PresidentialPardonForm& original )
{
	if (DEBUG) {
		std::cout << GREEN << "[PARDON] Calling Copy Assignement for ";
		std::cout << *this << STOP_COLOR << std::endl;
	}

	if (this == &original)
		return *this;

	AForm::operator=(original);
	_target = original._target;

	return *this;
}


//----------------- MEMBER FUNCTION -----------------//

void	PresidentialPardonForm::execute( const Bureaucrat& executor ) const
{
	if (!getIfSigned())
		throw IsNotYetSigned();
	if (executor.getGrade() > getGradeToExec())
		throw GradeTooLowException();

	std::cout << MAGENTA << _target << "has been pardonned by Zaphod Beeblebrox";
	std::cout << STOP_COLOR << std::endl;
}
