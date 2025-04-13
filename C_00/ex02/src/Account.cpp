#include <iostream>
#include <ctime>
#include "Account.hpp"

// private generic constructor
Account::Account( void )
{
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_amount = 0;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
};

// public constructor
Account::Account( int initial_deposit )
{
	_accountIndex = _nbAccounts;
	_nbAccounts++;
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
	int	previous_amount;

	previous_amount = _amount;
	_amount += deposit;
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "P_amount:" << previous_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_deposits:" << _nbDeposits << std::endl;
};

bool	Account::makeWithdrawal( int withdrawal ) {
	if (_amount < withdrawal)
		return (false);
	else
	{
		_amount -= withdrawal;
		return (true);
	}
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
	std::cout << "[" << time(NULL) << "] ";
};

void	Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawls:" << getNbWithdrawals() << std::endl;
};





