/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 18:31:13 by kdaniely          #+#    #+#             */
/*   Updated: 2024/06/16 20:46:00 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>

/* Initialization of static fields */
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

/* Constructor */
Account::Account(int initial_deposit)
{
	_displayTimestamp();
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_accountIndex = _nbAccounts ++;
	this->_totalAmount += initial_deposit;
	std::cout << " index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;
}

void	Account::_displayTimestamp()
{
	struct tm	*tm;
	time_t		t;

	t = time(0);
	tm = localtime(&t);
	std::cout << "[" << tm->tm_year + 1900;
	std::cout << std::setw(2) << std::setfill('0');
	std::cout << tm->tm_mday;
	std::cout << std::setw(2) << std::setfill('0');
	std::cout << tm->tm_mon + 1;
	std::cout << "_";
	std::cout << std::setw(2) << std::setfill('0');
	std::cout << tm->tm_hour;
	std::cout << std::setw(2) << std::setfill('0');
	std::cout << tm->tm_min;
	std::cout << std::setw(2) << std::setfill('0');
	std::cout << tm->tm_sec << "]";
}

void Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << " accounts:"<<_nbAccounts << ";";
	std::cout << "total:" <<_totalAmount << ";";
	std::cout << "deposits:" <<_totalNbDeposits <<";";
	std::cout << "withdrawals:" <<_totalNbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	_totalNbDeposits++;
	_nbDeposits++;
	std::cout << " index:" <<_accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "deposit:" << deposit << ";";
	_amount += deposit;
	std::cout << "amount:"<< _amount << ";";
	std::cout << "nb_deposits:" <<_nbDeposits << std::endl;
	_totalAmount += _amount;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "withdrawal:";
	_amount -=withdrawal;
	if (!checkAmount())
	{
		_amount += withdrawal;
		std::cout << "refused" << std::endl;
		_totalAmount += _amount;
		return (false);
	}
	_totalNbWithdrawals++;
	_totalAmount += _amount;
 	std::cout << withdrawal << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_withdrawals:" << ++_nbWithdrawals << std::endl;
	return (true);
	
}

void Account::displayStatus()const
{
	_displayTimestamp();
	_totalAmount = 0;
	std::cout << " index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}

int Account::checkAmount()const
{
	return (!(this->_amount <= 0));
}

int Account::getNbAccounts()
{
	return (_nbAccounts);
}

int Account::getTotalAmount()
{
	return (_totalAmount);
}

int Account::getNbDeposits()
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals()
{
	return (_totalNbWithdrawals);
}