#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	std::cout << std::endl << "STREAM OPERATOR" << std::endl;
	std::cout << "Let's check our form instances are printed";
	std::cout << " as we would like :" << std::endl << std::endl;

	Form		A("A", 1, 70);
	Form		B("B", 100, 150);
	Form		C("C", 150, 50);

	std::cout << A << std::endl;
	std::cout << B << std::endl;
	std::cout << C << std::endl;
	std::cout << std::endl;


	try {
		std::cout << std::endl << "CONSTRUCTOR EXCEPTION" << std::endl;
		std::cout << "Let's check our Form constructors throw ";
		std::cout << "exceptions if their grades are invalid :";
		std::cout << std::endl << std::endl;

		// remove the following catch to test error bubbling up to next scope
		try { Form	D("A", 0, 150); }
		catch (const Form::GradeTooHighException& e) {
			std::cerr << e.what() << std::endl; }
		catch (const Form::GradeTooLowException& e) {
			std::cerr << e.what() << std::endl; }

		try { Form	E("E", 1, -10); }
		catch (const Form::GradeTooHighException& e) {
			std::cerr << e.what() << std::endl; }

		try { Form	F("F", 1, 155); }
		catch (const std::exception& e) {
			std::cerr << e.what() << std::endl; }
		std::cout << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "End of scope bubble: " << e.what() << std::endl; }


	std::cout << std::endl << "SIGNING EXCEPTION" << std::endl;
	std::cout << "Let's check our signing methods throw ";
	std::cout << "exceptions if their signator are invalid :";
	std::cout << std::endl << std::endl;

	Bureaucrat	Larbin("Larbin", 150);
	Bureaucrat	Mid("Mid", 70);
	Bureaucrat	Noble("Noble", 1);

	std::cout << Larbin << std::endl;
	std::cout << Mid << std::endl;
	std::cout << Noble << std::endl;
	std::cout << std::endl;

	std::cout << "Trying to sign " << A << " with " << Larbin << std::endl;
	try { Larbin.signForm(A); }
	catch (const Form::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl; }
	std::cout << "Result: " << A << std::endl << std::endl;

	std::cout << "Trying to sign " << B << " with " << Larbin << std::endl;
	try { Larbin.signForm(B); }
	catch (const Form::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl; }
	std::cout << "Result: " << B << std::endl << std::endl;

	std::cout << "Trying to sign " << C << " with " << Larbin << std::endl;
	try { Larbin.signForm(C); }
	catch (const Form::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl; }
	std::cout << "Result: " << C << std::endl << std::endl;

	std::cout << "Trying to sign " << A << " with " << Noble << std::endl;
	try { Noble.signForm(A); }
	catch (const Form::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl; }
	std::cout << "Result: " << A << std::endl << std::endl;

	std::cout << "Trying to sign " << B << " with " << Noble << std::endl;
	try { Noble.signForm(B); }
	catch (const Form::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl; }
	std::cout << "Result: " << B << std::endl << std::endl;

	std::cout << "Trying to sign " << C << " with " << Noble << std::endl;
	try { Noble.signForm(C); }
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl; }
	std::cout << "Result: " << C << std::endl << std::endl;

}
