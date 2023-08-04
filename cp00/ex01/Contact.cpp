#include "PhoneBook.hpp"

void Contact::setFirstName(std::string firstName)
{
	this->firstName = firstName;
}

std::string	Contact::getFirstName(void)
{
	return (this->firstName);
}

void Contact::setLastName(std::string lastName)
{
	this->lastName = lastName;
}

std::string	Contact::getLastName(void)
{
	return (this->lastName);
}

void	Contact::setNickName(std::string nickName)
{
	this->nickName = nickName;
}

std::string	Contact::getNickName(void)
{
	return (this->nickName);
}

void	Contact::setPhoneNumber(std::string phoneNumber)
{
	this->phoneNumber = phoneNumber;
}

std::string	Contact::getPhoneNumber(void)
{
	return (this->phoneNumber);
}

void	Contact::setDarkestSecret(std::string darkestSecret)
{
	this->darkestSecret = darkestSecret;
}

std::string Contact::getDarkestSecret(void)
{
	return (this->darkestSecret);
}

Contact	createContact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret)
{
	Contact	newContact;

	newContact.setFirstName(firstName);
	newContact.setLastName(lastName);
	newContact.setNickName(nickName);
	newContact.setPhoneNumber(phoneNumber);
	newContact.setDarkestSecret(darkestSecret);

	return newContact;
}

int	addContact(Contact newContact, PhoneBook &newPhoneBook, int &index)
{
	Contact	*myCatalog;

	myCatalog = newPhoneBook.getCatalog();
	if (index == 8)
		index = 0;
	myCatalog[index] = newContact;
	index++;

	return 1;
}