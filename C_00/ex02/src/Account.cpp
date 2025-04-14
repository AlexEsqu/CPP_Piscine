#include <iostream>
#include <ctime>
#include "Account.hpp"

// private generic constructor
Account::Account( void )
{
	_accountIndex = getNbAccounts();
	_nbAccounts++;
	_amount = 0;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
};

// public constructor
Account::Account( int initial_deposit )
{
	// setting static variables
	_accountIndex = getNbAccounts();
	_totalAmount += initial_deposit;
	_nbAccounts++;

	// initializing the account
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;
};

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;
};

// METHODS FOR EACH ACCOUNT INSTANCE

void	Account::makeDeposit( int deposit ) {
	// setting static variables
	_totalNbDeposits++;
	_totalAmount += deposit;

	// setting account variables and log
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	_amount += deposit;
	_nbDeposits++;
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_deposits:" << _nbDeposits << std::endl;
};

bool	Account::makeWithdrawal( int withdrawal ) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "withdrawal:";

	if (_amount < withdrawal)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}

	std::cout << withdrawal << ";";
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (true);
};

int		Account::checkAmount( void ) const {
	return (_amount);
};

void	Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawls:" << _nbWithdrawals << std::endl;
};


// STATIC CLASS SPECIFIC FUNCTIONS

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void ) {
	return (_nbAccounts);
};


int	Account::getTotalAmount( void ) {
	return (_totalAmount);
};

int	Account::getNbDeposits( void ) {
	return (_totalNbDeposits);
};


int	Account::getNbWithdrawals( void ) {
	return (_totalNbWithdrawals);
};

void	Account::_displayTimestamp( void ) {

	std::time_t	now = std::time(0);
	std::tm		time_struct;
	char		buff[20];

	time_struct = *localtime(&now);
	strftime(buff, sizeof(buff), "[%Y%m%d_%H%M%S] ", &time_struct);

	std::cout << buff;
};

void	Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawls:" << getNbWithdrawals() << std::endl;
};





