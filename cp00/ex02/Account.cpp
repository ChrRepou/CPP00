#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <cctype>
#include <sstream>
#include <iomanip>

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
    std::cout << "index:" << SSTR(_accountIndex) << ";" << "p_amount:" << SSTR(_amount) << ";";
    this->_nbDeposits++;
    _totalNbDeposits++;
    this->_totalAmount += deposit;
    this->_amount += deposit;
    std::cout << "deposit:" << SSTR(deposit) << ";"
              << "amount:" << SSTR(_amount) << ";"
              << "nb_deposits:" << SSTR(_nbDeposits) << ";\n";
}

bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout << "index:" << SSTR(_accountIndex) << ";" << "p_amount:" << SSTR(_amount) << ";";
    if (this->_amount >= withdrawal && this->_totalAmount >= withdrawal)
    {
        this->_nbWithdrawals++;
        _totalNbWithdrawals++;
        this->_amount -= withdrawal;
        this->_totalAmount -= withdrawal;
        std::cout << "withdrawal:" << SSTR(withdrawal) << ";"
                  << "amount:" << SSTR(_amount) << ";"
                  << "nb_withdrawals:" << SSTR(_nbWithdrawals) << ";\n";
        return (1);
    }
    std::cout << "withdrawal:" << "refused" << ";\n";
    return (0);
}

void Account::_displayTimestamp()
{
    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);
    std::cout << "[" << std::setfill('0') << std::setw(4) << (now->tm_year + 1900)
              << std::setw(2) << (now->tm_mon + 1)
              << std::setw(2) <<  now->tm_mday << "_" 
              << std::setw(2) << now->tm_hour + 2
              << std::setw(4) << now->tm_min
              << std::setw(4) << now->tm_sec
              << "] ";
}

Account::Account( int initial_deposit )
{
    _displayTimestamp();
    _nbAccounts++;
    _totalAmount += initial_deposit;
    _amount = initial_deposit;
    _accountIndex = _nbAccounts - 1;
    std::cout << "index:" << SSTR(_accountIndex) << ";"
              << "amount:" << SSTR(_amount) << ";"
              << "created\n";
}

void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << SSTR(_nbAccounts) << ";" 
              << "total:" << SSTR(_totalAmount) << ";"
              << "deposits:" << SSTR(_totalNbDeposits) << ";"
              << "withdrawals:" << SSTR(_totalNbWithdrawals) << ";\n";
}

void Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << SSTR(_accountIndex) << ";"
              << "amount:" << SSTR(_amount) << ";"
              << "deposits:" << SSTR(_nbDeposits) << ";"
              << "withdrawals:" << SSTR(_nbWithdrawals) << ";\n";
}

Account::~Account( void )
{
    _displayTimestamp();
    std::cout << "index:" << SSTR(_accountIndex) << ";"
              << "amount:" << SSTR(_amount) << ";"
              << "closed\n";
}
