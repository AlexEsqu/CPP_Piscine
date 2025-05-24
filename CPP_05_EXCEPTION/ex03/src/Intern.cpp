#include "Intern.hpp"

//----------------- CONSTRUCTORS ---------------------//

Intern::Intern()
{
	if (DEBUG) {
		std::cout << GREEN << "[Intern] Calling Constructor";
		std::cout << STOP_COLOR << std::endl;
	}

	_formMatches = new FormMatch[3];

	_formMatches[0].type = "shrubbery creation";
	_formMatches[0].constructor = &Intern::_make_shrubbery ;
	_formMatches[1].type = "presidential pardon";
	_formMatches[1].constructor = &Intern::_make_pardon ;
	_formMatches[2].type = "robotomy request",
	_formMatches[2].constructor = &Intern::_make_request ;

}

//----------------- DESTRUCTORS ---------------------//

Intern::~Intern()
{
	if (DEBUG) {
		std::cout << RED << "[Intern] Calling Destructor";
		std::cout << STOP_COLOR << std::endl;
	}

	delete[] _formMatches;
}

//----------------- COPY CONSTRUCTORS ----------------//

Intern::Intern( const Intern& original )
{
	if (DEBUG) {
		std::cout << GREEN << "[Intern] Calling Copy Constructor";
		std::cout << STOP_COLOR << std::endl;
	}

	_formMatches = new FormMatch[3];

	for (size_t i = 0; i < 3; i++) {
		_formMatches[i].type = original._formMatches[i].type;
		_formMatches[i].constructor = original._formMatches[i].constructor;
	}

}

//----------------- COPY ASSIGNEMENT -----------------//

Intern&				Intern::operator=( const Intern& original )
{
	if (DEBUG) {
		std::cout << GREEN << "[INTERN] Calling Copy Assignement";
		std::cout << STOP_COLOR << std::endl;
	}

	if (this != &original)
		return *this;
	return *this;
}


//----------------- MEMBER FUNCTION -----------------//

AForm		*Intern::_make_shrubbery( const std::string& target )
{
	return new ShrubberyCreationForm(target);
}

AForm		*Intern::_make_pardon( const std::string& target )
{
	return new PresidentialPardonForm(target);
}

AForm		*Intern::_make_request( const std::string& target )
{
	return new RobotomyRequestForm(target);
}


AForm*		Intern::makeForm( std::string formType, std::string target )
{
	for (size_t i = 0; i < 3; i++) {
		if (_formMatches[i].type.compare(formType) == 0) {
			std::cout << "Intern creates " << _formMatches[i].type << std::endl;
			return _formMatches[i].constructor(target);
		}
	}

	throw NonExistentForm();

}

//----------------- EXCEPTIONS ---------------------//

const char* Intern::NonExistentForm::what() const throw()
{
	return "ERROR: This form does not exist...";
}
