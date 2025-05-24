#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

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

	FormFolder[2] = new ShrubberyCreationForm("Home");
	std::cout << *FormFolder[2] << std::endl;



	std::cout << std::endl << "SIGNING FORMS" << std::endl;
	std::cout << "Let's check our forms can be signed by the expected ";
	std::cout << "bureaucrats or throw the right errors :";
	std::cout << std::endl << std::endl;

	Bureaucrat	Larbin("Larbin", 120);
	Bureaucrat	Mid("Mid", 15);
	Bureaucrat	Noble("Noble", 1);

	std::cout <<  Larbin << "tried to sign " << *FormFolder[0] << std::endl;
	try { Larbin.signForm(*FormFolder[0]); }
	catch (const AForm::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl; }
	std::cout << "Result: " << *FormFolder[0] << std::endl << std::endl;

	std::cout <<  Noble << "tried to sign " << *FormFolder[0] << std::endl;
	try { Noble.signForm(*FormFolder[0]); }
	catch (const AForm::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl; }
	std::cout << "Result: " << *FormFolder[0] << std::endl << std::endl;

	std::cout <<  Noble << "tried to sign " << *FormFolder[1] << std::endl;
	try { Noble.signForm(*FormFolder[1]); }
	catch (const AForm::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl; }
	std::cout << "Result: " << *FormFolder[1] << std::endl << std::endl;

	std::cout <<  Noble << "tried to sign " << *FormFolder[2] << std::endl;
	try { Noble.signForm(*FormFolder[2]); }
	catch (const AForm::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl; }
	std::cout << "Result: " << *FormFolder[2] << std::endl << std::endl;



	std::cout << std::endl << "EXECUTING FORMS" << std::endl;
	std::cout << "Let's check our forms can be executed ";
	std::cout << "and produce the expected results :";
	std::cout << std::endl << std::endl;

	std::cout <<  Larbin << " trying to execute " << *FormFolder[0] << std::endl;
	try { Larbin.executeForm(*FormFolder[0]); }
	catch (const AForm::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl; }
	std::cout << std::endl;

	std::cout <<  Noble << " trying to execute " << *FormFolder[0] << std::endl;
	try { Noble.executeForm(*FormFolder[0]); }
	catch (const AForm::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl; }
	std::cout << std::endl;

	std::cout << Mid << " trying to execute " << *FormFolder[1] << std::endl;
	try { Mid.executeForm(*FormFolder[1]); }
	catch (const AForm::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl; }
	std::cout << std::endl;

	std::cout << Larbin << " trying to execute " << *FormFolder[2] << std::endl;
	try { Larbin.executeForm(*FormFolder[2]); }
	catch (const AForm::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl; }
	std::cout << std::endl;


	for (int i = 0; i < 3; i++) {
		delete FormFolder[i];
	}
}
