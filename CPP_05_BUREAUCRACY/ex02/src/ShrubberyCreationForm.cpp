#include "ShrubberyCreationForm.hpp"

//----------------- CONSTRUCTORS ---------------------//

ShrubberyCreationForm::ShrubberyCreationForm( std::string target )
	: AForm( "Shrubbery Creation Form", 25, 5 )
	, _target(target)
{
	if (DEBUG) {
		std::cout << GREEN << "[SHRUB] Calling Constructor for ";
		std::cout << *this << STOP_COLOR << std::endl;
	}
}

//----------------- DESTRUCTORS ---------------------//

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	if (DEBUG) {
		std::cout << RED << "[SHRUB] Calling Destructor for ";
		std::cout << *this << STOP_COLOR << std::endl;
	}
}

//----------------- COPY CONSTRUCTORS ----------------//

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& original )
	: AForm(original)
{
	if (DEBUG) {
		std::cout << GREEN << "[SHRUB] Calling Copy Constructor for ";
		std::cout << original << STOP_COLOR << std::endl;
	}
}

//----------------- COPY ASSIGNEMENT -----------------//

ShrubberyCreationForm&	ShrubberyCreationForm::operator=( const ShrubberyCreationForm& original )
{
	if (DEBUG) {
		std::cout << GREEN << "[SHRUB] Calling Copy Assignement for ";
		std::cout << *this << STOP_COLOR << std::endl;
	}

	if (this == &original)
		return *this;

	AForm::operator=(original);
	_target = original._target;

	return *this;
}

//----------------- MEMBER FUNCTION -----------------//

void	ShrubberyCreationForm::execute( const Bureaucrat& executor )
{
	if (!getIfSigned())
		throw IsNotYetSigned();
	if (executor.getGrade() > getGradeToExec())
		throw GradeTooLowException();

	std::cout << "Whhhhrrrrrrrrrr..... ZZZZZzzzzhhhh..... " << std::endl;
	std::srand(std::time(0));
	if (std::rand())
		std::cout << _target << "has been successfully robotomized";
	else
		std::cout << _target << "'s robotomy has failed...";
	std::cout << std::endl;
}
