#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <cctype>
#include <sstream>

#define SSTR( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()
using namespace std;

class Contact
{
	public:
		string	firstName;
		string	lastName;
		string	nickName;
		string	phoneNumber;
		string	darkestSecret;
};

class PhoneBook
{
	public:
		Contact catalog[8];
};

#endif