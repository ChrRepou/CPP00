#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <cctype>
#include <sstream>
#include <limits>

#define SSTR( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

class Contact
{
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	phoneNumber;
		std::string	darkestSecret;

	public:
		void setFirstName(std::string firstName)
		{
			this->firstName = firstName;
		}

		std::string	getFirstName(void)
		{
			return (this->firstName);
		}

		void setLastName(std::string lastName)
		{
			this->lastName = lastName;
		}

		std::string	getLastName(void)
		{
			return (this->lastName);
		}

		void	setNickName(std::string nickName)
		{
			this->nickName = nickName;
		}

		std::string	getNickName(void)
		{
			return (this->nickName);
		}

		void	setPhoneNumber(std::string phoneNumber)
		{
			this->phoneNumber = phoneNumber;
		}

		std::string	getPhoneNumber(void)
		{
			return (this->phoneNumber);
		}

		void	setDarkestSecret(std::string darkestSecret)
		{
			this->darkestSecret = darkestSecret;
		}

		std::string getDarkestSecret(void)
		{
			return (this->darkestSecret);
		}
};

class PhoneBook
{
	private:
		Contact catalog[8];

	public:

		void setCatalog(Contact myCatalog[])
    	{
        	for (int i = 0; i < 8; ++i) {
        	    this->catalog[i] = myCatalog[i];
        	}
    	}

		Contact* getCatalog()
    	{
			return (this->catalog);
		}
};

#endif