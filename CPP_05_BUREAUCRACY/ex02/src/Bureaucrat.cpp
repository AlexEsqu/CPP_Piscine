#include "Bureaucrat.hpp"

//----------------- CONSTRUCTORS ---------------------//

Bureaucrat::Bureaucrat( const std::string name, int grade )
	: _name(name)
	, _grade(grade)
{
	if (DEBUG) {
		std::cout << GREEN << "[BUREAUCRAT] Calling Constructor for ";
		std::cout << *this << STOP_COLOR << std::endl;
	}

	if (grade < 1) {
		if (DEBUG) {
			std::cout << RED << "[BUREAUCRAT] Invalid grade for ";
			std::cout << *this << STOP_COLOR << std::endl;
		}
		throw GradeTooHighException();
	}

	if (grade > 150) {
		if (DEBUG) {
			std::cout << RED << "[BUREAUCRAT] Invalid grade for ";
			std::cout << *this << STOP_COLOR << std::endl;
		}
		throw GradeTooLowException();
	}
}

//----------------- DESTRUCTORS ---------------------//

Bureaucrat::~Bureaucrat()
{
	if (DEBUG) {
		std::cout << RED << "[BUREAUCRAT] Calling Destructor for ";
		std::cout << *this << STOP_COLOR << std::endl;
	}
}

//----------------- COPY CONSTRUCTORS ----------------//

Bureaucrat::Bureaucrat( const Bureaucrat& original )
	: _name(original.getName())
	, _grade(original.getGrade())
{
	if (DEBUG) {
		std::cout << GREEN << "[BUREAUCRAT] Calling Copy Constructor for ";
		std::cout << original << STOP_COLOR << std::endl;
	}
}

//----------------- COPY ASSIGNEMENT -----------------//

Bureaucrat&				Bureaucrat::operator=( const Bureaucrat& original )
{
	if (DEBUG) {
		std::cout << GREEN << "[BUREAUCRAT] Calling Copy Assignement for ";
		std::cout << original << STOP_COLOR << std::endl;
	}

	if (this == &original)
		return *this;

	_grade =  original.getGrade();
	// _name is const and cannot be modified

	return *this;
}


//----------------- MEMBER FUNCTION -----------------//

const std::string		Bureaucrat::getName() const
{
	return _name;
}

int						Bureaucrat::getGrade() const
{
	return _grade;
}

void					Bureaucrat::incrementGrade()
{
	if (_grade <= 1)
		throw GradeTooHighException();
	else
		_grade--;
}

void					Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
		throw GradeTooLowException();
	else
		_grade++;
}

void					Bureaucrat::signForm( AForm& form )
{
	try { form.beSigned(*this); }
	catch (const AForm::GradeTooLowException& e)
	{
		std::cout << "ERROR: ";
		std::cout << getName() << " couldn't sign " << form.getName();
		std::cout << " because " << getName() << "'s grade is too low.";
		std::cout << std::endl;
		return ;
	}

	std::cout << getName() << " signed " << form.getName();
	std::cout << "." << std::endl;
}

//----------------- EXCEPTIONS ---------------------//

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "ERROR: Grade is too high !";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "ERROR: Grade is too low !";
}

//----------------- VISUALIZATION -----------------//

std::ostream& operator<<( std::ostream& out, const Bureaucrat& b )
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (out);
}


