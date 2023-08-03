#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <cctype>
#include <sstream>

#define SSTR( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

int Account::_nbAccounts = 0;
int Account::_totalAmount= 0;
int Account::_totalNbDeposits= 0;
int Account::_totalNbWithdrawals = 0;

int Account::checkAmount(void) const
{
    return (this->_amount);
}

int Account::getNbDeposits(void)
{
    return (_totalNbDeposits);
}

int Account::getNbAccounts(void)
{
    return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
    return (_totalAmount);
}

int Account::getNbWithdrawals(void)
{
    return (_totalNbWithdrawals);
}

void   Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout << "index:" << SSTR(_accountIndex) << ";";
    std::cout << "p_amount:" << SSTR(_amount) << ";";
    this->_nbDeposits++;
    _totalNbDeposits++;
    this->_totalAmount += deposit;
    this->_amount += deposit;
    std::cout << "deposit:" << SSTR(deposit) << ";";
    std::cout << "amount:" << SSTR(_amount) << ";";
    std::cout << "nb_deposits:" << SSTR(_nbDeposits) << ";\n";
}

bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout << "index:" << SSTR(_accountIndex) << ";";
    std::cout << "p_amount:" << SSTR(_amount) << ";";
    if (this->_amount >= withdrawal && this->_totalAmount >= withdrawal)
    {
        this->_nbWithdrawals++;
        _totalNbWithdrawals++;
        this->_amount -= withdrawal;
        this->_totalAmount -= withdrawal;
        std::cout << "withdrawal:" << SSTR(withdrawal) << ";";
        std::cout << "amount:" << SSTR(_amount) << ";";
        std::cout << "nb_withdrawals:" << SSTR(_nbWithdrawals) << ";\n";
        return (1);
    }
    std::cout << "withdrawal:" << "refused" << ";\n";
    return (0);
}

void Account::_displayTimestamp()
{
    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);
    std::cout << "[" << (now->tm_year + 1900)
         << (now->tm_mon + 1)
         <<  now->tm_mday << "_" ;
    if (now->tm_hour < 10)
        std::cout << "0" << now->tm_hour + 2;
    else
        std::cout << now->tm_hour + 2;
    if (now->tm_min < 10)
        std::cout << "0" << now->tm_min;
    else
        std::cout << now->tm_min;
    if (now->tm_sec < 10)
        std::cout << "0" << now->tm_sec;
    else
        std::cout << now->tm_sec;
    std::cout << "] ";
}

Account::Account( int initial_deposit )
{
    _displayTimestamp();
    _nbAccounts++;
    _totalAmount += initial_deposit;
    _amount = initial_deposit;
    _accountIndex = _nbAccounts - 1;
    std::cout << "index:" << SSTR(_accountIndex) << ";";
    std::cout << "amount:" << SSTR(_amount) << ";";
    std::cout << "created\n";
}

void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << SSTR(_nbAccounts) << ";" ;
    std::cout << "total:" << SSTR(_totalAmount) << ";";
    std::cout << "deposits:" << SSTR(_totalNbDeposits) << ";";
    std::cout << "withdrawals:" << SSTR(_totalNbWithdrawals) << ";\n";
}

void Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << SSTR(_accountIndex) << ";";
    std::cout << "amount:" << SSTR(_amount) << ";";
    std::cout << "deposits:" << SSTR(_nbDeposits) << ";";
    std::cout << "withdrawals:" << SSTR(_nbWithdrawals) << ";\n";
}

Account::~Account( void )
{
    _displayTimestamp();
    std::cout << "index:" << SSTR(_accountIndex) << ";";
    std::cout << "amount:" << SSTR(_amount) << ";";
    std::cout << "closed\n";
}
