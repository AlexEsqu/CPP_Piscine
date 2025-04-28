#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShruberryCreationForm.hpp"

int	main()
{
	std::cout << std::endl << "STREAM OPERATOR" << std::endl;
	std::cout << "Let's check our Form instances are printed";
	std::cout << " as we would like :" << std::endl << std::endl;

	AForm*	FormFolder[3];

	FormFolder[0] = new PresidentialPardonForm("Neron");
	std::cout << *FormFolder[0] << std::endl;

	FormFolder[1] = new RobotomyRequestForm("Bender");
	std::cout << *FormFolder[1] << std::endl;


	// std::cout << B << std::endl;
	// std::cout << C << std::endl;
	// std::cout << std::endl;


	std::cout << std::endl << "EXECUTING FORMS" << std::endl;
	std::cout << "Let's check our forms can be executed ";
	std::cout << "and produce the expected results :";
	std::cout << std::endl << std::endl;

	Bureaucrat	Larbin("Larbin", 150);
	Bureaucrat	Mid("Mid", 70);
	Bureaucrat	Noble("Noble", 1);

	std::cout << "Trying to sign " << *FormFolder[0] << " with ";
	std::cout << Larbin << std::endl;
	try { Larbin.signForm(*FormFolder[0]); }
	catch (const AForm::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl; }
	std::cout << "Result: " << *FormFolder[0] << std::endl << std::endl;

	std::cout << "Trying to sign " << *FormFolder[0] << " with ";
	std::cout << Noble << std::endl;
	try { Noble.signForm(*FormFolder[0]); }
	catch (const AForm::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl; }
	std::cout << "Result: " << *FormFolder[0] << std::endl << std::endl;



}
