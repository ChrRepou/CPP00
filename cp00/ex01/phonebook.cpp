#include "phonebook.hpp"
#include <limits>

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

void	printContacts(PhoneBook myPhoneBook)
{
	int	i;

	i = 0;
	cout << "index     |";
	cout << "first name|";
	cout << "last name |";
	cout << "nick name\n";
	while(i < 8)
	{
		if (myPhoneBook.catalog[i].firstName.empty())
			break;
		string	index_str = SSTR(i + 1);
		for (long unsigned int j = 0; j < 10; j++)
		{
			if (j < index_str.length())
				cout << index_str[j];
			else
				cout << " ";
		}
		cout << "|";

		for (long unsigned int j = 0; j < 10; j++)
		{
			if (j < myPhoneBook.catalog[i].firstName.length() && j == 9)
				cout << ".";
			else if (j < myPhoneBook.catalog[i].firstName.length())
				cout << myPhoneBook.catalog[i].firstName[j];
			else
				cout << " ";
		}
		cout << "|";

		for (long unsigned int j = 0; j < 10; j++)
		{
			if (j < myPhoneBook.catalog[i].lastName.length() && j == 9)
				cout << ".";
			else if (j < myPhoneBook.catalog[i].lastName.length())
				cout << myPhoneBook.catalog[i].lastName[j];
			else
				cout << " ";
		}
		cout << "|";

		for (long unsigned int j = 0; j < 10; j++)
		{
			if (j < myPhoneBook.catalog[i].nickName.length() && j == 9)
				cout << ".";
			else if (j < myPhoneBook.catalog[i].nickName.length())
				cout << myPhoneBook.catalog[i].nickName[j];
			else
				cout << " ";
		}
		cout << "\n";
		i++;
	}
}

void	printSpecificContact(PhoneBook myPhoneBook, int index, int maxCurrIndex)
{
	Contact	selectedContact;

	if (index == 0)
		cout << "This is not a valid index\n";
	else if (index > maxCurrIndex || index > 8)
		cout << "Index: " + SSTR(index) + " is not a valid index\n";
	else
	{
		selectedContact = myPhoneBook.catalog[index - 1];
		cout << "First name: " + selectedContact.firstName << endl;
		cout << "Last name: " + selectedContact.lastName << endl;
		cout << "Nick name: " + selectedContact.nickName << endl;
		cout << "Phone number: " + selectedContact.phoneNumber << endl;
		cout << "Darkest secret: " + selectedContact.darkestSecret << endl;
	}
}

void	executeSearch(PhoneBook myPhoneBook, int currentMaxIndex)
{
	string	selected_index_str;
	int		selected_index;
	stringstream ss;

	printContacts(myPhoneBook);
	cout << "Give the index of the Contact you wanna see\n";
	getline(cin, selected_index_str);
	ss << selected_index_str;
	ss >> selected_index; 
	printSpecificContact(myPhoneBook, selected_index, currentMaxIndex);
}

void	executeAdd(int &index, PhoneBook &phoneBook)
{
	string	firstName;
	string	lastName;
	string	nickName;
	string	phoneNumber;
	string	darkestSecret;
	Contact	newContact;

	do{
		cout << "Give your first name: ";
		getline(cin, firstName);
		if (firstName.empty())
			cout << "This field shouldn't be empty\n";
	} while (firstName.empty());
	
	do{
		cout << "\nGive your last name: ";
		getline(cin, lastName);
		if (lastName.empty())
			cout << "This field shouldn't be empty\n";
	} while (lastName.empty());

	do{
		cout << "\nGive your nickName: ";
		getline(cin, nickName);
		if (nickName.empty())
			cout << "This field shouldn't be empty\n";
	} while (nickName.empty());
	
	do{
		cout << "\nGive your phone number: ";
		getline(cin, phoneNumber);
		if (phoneNumber.empty())
			cout << "This field shouldn't be empty\n";
	} while (phoneNumber.empty());

	do{
		cout << "\nGive your darkest secret: ";
		getline(cin, darkestSecret);
		if (darkestSecret.empty())
			cout << "This field shouldn't be empty\n";
	} while (darkestSecret.empty());

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
		getline(cin, command);
		if (cin.eof())
			exit(1);
		if (command == "EXIT")
			break;
		else if (command == "ADD")
			executeAdd(index, myPhoneBook);
		else if (command == "SEARCH")
			executeSearch(myPhoneBook, index);
		else
			cout << "Command: " + command + " is not acceptable!\n";

	}
	// cout << "Index before adding the contact: " + SSTR(index) + " \n";
	// cout << "Index after adding the contact: " + SSTR(index) + " \n";



	return 0;
}
