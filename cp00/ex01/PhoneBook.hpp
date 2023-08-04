#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <cctype>
#include <limits>
#include "Contact.hpp"

#define SSTR( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()


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

void	executeAdd(int &index, PhoneBook &phoneBook);
void	executeSearch(PhoneBook myPhoneBook, int currentMaxIndex);
void	printSpecificContact(PhoneBook myPhoneBook, int index, int maxCurrIndex);
void	printContacts(PhoneBook myPhoneBook);
int		addContact(Contact newContact, PhoneBook &newPhoneBook, int &index);
#endif