#include "Bureaucrat.hpp"

int	main()
{
	std::cout << std::endl << "STREAM OPERATOR" << std::endl;
	std::cout << "Let's check our class instances are printed";
	std::cout << " as we would like :" << std::endl << std::endl;

	Bureaucrat	Larbin("Larbin", 150);
	Bureaucrat	Mid("Mid", 70);
	Bureaucrat	Noble("Noble", 1);

	std::cout << Larbin << std::endl;
	std::cout << Mid << std::endl;
	std::cout << Noble << std::endl;
	std::cout << std::endl;


	std::cout << std::endl << "CONSTRUCTOR EXCEPTION" << std::endl;
	std::cout << "Let's check our class constructors throw ";
	std::cout << "exceptions if their grades are invalid :";
	std::cout << std::endl << std::endl;

	try { Bureaucrat	GodMode("GodMode", 0); }
	catch (const Bureaucrat::GradeTooHighException& e) {
		std::cerr << e.what() << std::endl; }
	catch (const Bureaucrat::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl; }

	try { Bureaucrat	Ghost("Ghost", 160); }
	catch (const Bureaucrat::GradeTooHighException& e) {
		std::cerr << e.what() << std::endl; }
	catch (const Bureaucrat::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl; }

	try { Bureaucrat	Genie("Genie", -10); }
	catch (const Bureaucrat::GradeTooHighException& e) {
		std::cerr << e.what() << std::endl; }
	catch (const Bureaucrat::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl; }
	std::cout << std::endl;


	std::cout << std::endl << "INCREMENT EXCEPTION" << std::endl;
	std::cout << "Let's check our increment methods throw ";
	std::cout << "exceptions if their results are invalid :";
	std::cout << std::endl << std::endl;

	std::cout << "Trying to decrement " << Larbin << std::endl;
	try { Larbin.decrementGrade(); }
	catch (const Bureaucrat::GradeTooHighException& e) {
		std::cerr << e.what() << std::endl; }
	catch (const Bureaucrat::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl; }
	std::cout << "Result: " << Larbin << std::endl << std::endl;

	std::cout << "Trying to increment " << Noble << std::endl;
	try { Noble.incrementGrade(); }
	catch (const Bureaucrat::GradeTooHighException& e) {
		std::cerr << e.what() << std::endl; }
	catch (const Bureaucrat::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl; }
	std::cout << "Result: " << Noble << std::endl << std::endl;

	std::cout << "Trying to decrement " << Mid << std::endl;
	try { Mid.decrementGrade(); }
	catch (const Bureaucrat::GradeTooHighException& e) {
		std::cerr << e.what() << std::endl; }
	catch (const Bureaucrat::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl; }
	std::cout << "Result: " << Mid << std::endl << std::endl;

}
