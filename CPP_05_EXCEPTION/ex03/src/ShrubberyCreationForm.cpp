#include "ShrubberyCreationForm.hpp"

//----------------- CONSTRUCTORS ---------------------//

ShrubberyCreationForm::ShrubberyCreationForm( std::string target )
	: AForm( "Shrubbery Creation Form", 145, 137 )
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

const std::string	ShrubberyCreationForm::_forest =
"               ,@@@@@@@,\n"
"       ,,,.   ,@@@@@@@@@,  .oo8888o.\n"
"    ,&%%&%&&%,@@@@@@@@@@@@,888888888o\n"
"   ,%&%%&&%&&%,@@@@@@@/@@@88888888888'\n"
"   %&&%&%&%%&&%@@@@@/ /@@@88888888888'\n"
"   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
"   `&%\\ ` /%&'    |.|        \\ '|8'\n"
"       |o|        | |         | |\n"
"       |.|        | |         | |\n"
"    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_";

void	ShrubberyCreationForm::execute( const Bureaucrat& executor ) const
{
	if (!getIfSigned())
		throw IsNotYetSigned();
	if (executor.getGrade() > getGradeToExec())
		throw GradeTooLowException();

	std::string		shrubFileName = _target;
	shrubFileName.append("_shrubbery");

	std::ofstream	shrub(shrubFileName.c_str());
	shrub << _forest;

	std::cout << GREEN << _target << "_shruberry has been shruberrized";
	std::cout << STOP_COLOR << std::endl;
}
