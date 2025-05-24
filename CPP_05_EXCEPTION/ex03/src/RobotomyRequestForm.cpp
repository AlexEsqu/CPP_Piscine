#include "RobotomyRequestForm.hpp"

//----------------- CONSTRUCTORS ---------------------//

RobotomyRequestForm::RobotomyRequestForm( std::string target )
	: AForm( "Robotomy Request", 72, 45 )
	, _target(target)
{
	if (DEBUG) {
		std::cout << GREEN << "[REQUEST] Calling Constructor for ";
		std::cout << *this << STOP_COLOR << std::endl;
	}
}

//----------------- DESTRUCTORS ---------------------//

RobotomyRequestForm::~RobotomyRequestForm()
{
	if (DEBUG) {
		std::cout << RED << "[REQUEST] Calling Destructor for ";
		std::cout << *this << STOP_COLOR << std::endl;
	}
}

//----------------- COPY CONSTRUCTORS ----------------//

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& original )
	: AForm(original)
{
	if (DEBUG) {
		std::cout << GREEN << "[REQUEST] Calling Copy Constructor for ";
		std::cout << original << STOP_COLOR << std::endl;
	}
}

//----------------- COPY ASSIGNEMENT -----------------//

RobotomyRequestForm&	RobotomyRequestForm::operator=( const RobotomyRequestForm& original )
{
	if (DEBUG) {
		std::cout << GREEN << "[REQUEST] Calling Copy Assignement for ";
		std::cout << *this << STOP_COLOR << std::endl;
	}

	if (this == &original)
		return *this;

	AForm::operator=(original);
	_target = original._target;

	return *this;
}

//----------------- MEMBER FUNCTION -----------------//

void	RobotomyRequestForm::execute( const Bureaucrat& executor ) const
{
	if (!getIfSigned())
		throw IsNotYetSigned();
	if (executor.getGrade() > getGradeToExec())
		throw GradeTooLowException();

	std::cout << "Whhhhrrrrrrrrrr..... ZZZZZzzzzhhhh..... " << std::endl;
	std::srand(std::time(0));
	if (std::rand() % 2)
		std::cout << YELLOW << _target << " has been successfully robotomized";
	else
		std::cout << RED << _target << "'s robotomy has failed...";
	std::cout << STOP_COLOR << std::endl;
}
