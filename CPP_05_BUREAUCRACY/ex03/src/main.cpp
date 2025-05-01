#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main()
{
	{
		std::cout << std::endl << "MODULE SUGGESTED TEST" << std::endl;
		std::cout << "Let's check our Intern can create a form :";
		std::cout << std::endl << std::endl;


		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");

		// added to print out effects
		std::cout << *rrf << std::endl;
		// added to free memory
		delete rrf;
	}

	{
		std::cout << std::endl << "MODERN SWEATSHOP" << std::endl;
		std::cout << "Let's industrialize this form production pipeline :";
		std::cout << std::endl << std::endl;


		Intern		someOtherRandomIntern;
		AForm*		formFolder[3];

		formFolder[0] = someOtherRandomIntern.makeForm("shrubbery creation", "Home");
		std::cout << *formFolder[0] << std::endl;

		formFolder[1] = someOtherRandomIntern.makeForm("robotomy request", "Luce");
		std::cout << *formFolder[1] << std::endl;

		formFolder[2] = someOtherRandomIntern.makeForm("presidential pardon", "Valentine");
		std::cout << *formFolder[2] << std::endl;

		Bureaucrat	Stackanov("Stackanov", 1);

		for (int i = 0; i < 3; i++) {
			Stackanov.signForm(*formFolder[i]);
			Stackanov.executeForm(*formFolder[i]);
		}
	}

	{
		std::cout << std::endl << "INVALID INSTRUCTIONS" << std::endl;
		std::cout << "Let's check our interns can warn us if they ";
		std::cout << "receive an invalid instruction :" << std::endl << std::endl;

		Intern		yetAnotherRandomIntern;

		std::cout << "Trying to create <birthday party> form:" << std::endl << std::endl;
		try
		{
			AForm* formFolder = yetAnotherRandomIntern.makeForm("birthday party", "Home");
			std::cout << *formFolder << std::endl;
		}
		catch ( const Intern::NonExistentForm& e )
		{
			std::cerr << e.what() << std::endl;
		}

	}



}
