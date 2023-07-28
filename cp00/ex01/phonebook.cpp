#include "phonebook.hpp"

Contact	createContact(string firstName, string lastName, string nickName, string phoneNumber, string darkestSecret)
{
	Contact	newContact;

	newContact.firstName = firstName;
	newContact.lastName = lastName;
	newContact.nickName = nickName;
	newContact.phoneNumber = phoneNumber;
	newContact.darkestSecret = darkestSecret;

	return newContact;
}

int	addContact(Contact newContact, PhoneBook &newPhoneBook, int &index)
{
	if (index == 8)
		index = 0;
	newPhoneBook.catalog[index] = newContact;
	index++;

	return 1;
}

void	executeAdd(int &index, PhoneBook &phoneBook)
{
	string	firstName;
	string	lastName;
	string	nickName;
	string	phoneNumber;
	string	darkestSecret;
	Contact	newContact;

	do {
		cout << "Give your first name: ";
		cin >> firstName;
		if (firstName.empty())
			cout << "\nYou shouldn't leave this blank!";
	} while(firstName.empty());

	do {
		cout << "\nGive your last name: ";
		cin >> lastName;
		if (lastName.empty())
			cout << "\nYou shouldn't leave this blank!";
	} while(lastName.empty());
	
	do {
		cout << "\nGive your nickName: ";
		cin >> nickName;
		if (nickName.empty())
			cout << "\nYou shouldn't leave this blank!";
	} while(nickName.empty());

	do {
		cout << "\nGive your phone number: ";
		cin >> phoneNumber;
		if (phoneNumber.empty())
			cout << "\nYou shouldn't leave this blank!";
	} while(phoneNumber.empty());

	do {
		cout << "\nGive your darkest secret: ";
		cin >> darkestSecret;
		if (darkestSecret.empty())
			cout << "\nYou shouldn't leave this blank!";
	} while(darkestSecret.empty());
	cout << "\n";

	newContact = createContact(firstName, lastName, nickName, phoneNumber, darkestSecret);
	addContact(newContact, phoneBook, index); 
}

int main()
{
	PhoneBook	myPhoneBook;
	Contact		myContact;
	int			index;
	string		command;

	index = 0;
	cout << "Welcome to the phoneBook!\n";
	cout << "Available commands:\n";
	cout << "ADD: adding a new Contact to the phoneBook\n";
	cout << "SEARCH: display a specific contact\n";
	cout << "EXIT: to terminate the program\n";

	while (1)
	{
		cout << "Give a command: ";
		cin >> command;
		if (command == "EXIT")
			break;
		else if (command == "ADD")
			executeAdd(index, myPhoneBook);
		else
			cout << "Command: " + command + " is not acceptable!\n";

	}
	// cout << "Index before adding the contact: " + SSTR(index) + " \n";
	// cout << "Index after adding the contact: " + SSTR(index) + " \n";



	return 0;
}
