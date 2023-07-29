#include "phonebook.hpp"

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

void	printContacts(PhoneBook myPhoneBook)
{
	int	i;
	Contact	*myCatalog;

	myCatalog = myPhoneBook.getCatalog();
	i = 0;
	std::cout << "index     |";
	std::cout << "first name|";
	std::cout << "last name |";
	std::cout << "nick name\n";
	while(i < 8)
	{
		if (myCatalog[i].getFirstName().empty())
			break;
		std::string	index_str = SSTR(i + 1);
		for (long unsigned int j = 0; j < 10; j++)
		{
			if (j < index_str.length())
				std::cout << index_str[j];
			else
				std::cout << " ";
		}
		std::cout << "|";

		for (long unsigned int j = 0; j < 10; j++)
		{
			if (j < myCatalog[i].getFirstName().length() && j == 9)
				std::cout << ".";
			else if (j < myCatalog[i].getFirstName().length())
				std::cout << myCatalog[i].getFirstName()[j];
			else
				std::cout << " ";
		}
		std::cout << "|";

		for (long unsigned int j = 0; j < 10; j++)
		{
			if (j < myCatalog[i].getLastName().length() && j == 9)
				std::cout << ".";
			else if (j < myCatalog[i].getLastName().length())
				std::cout << myCatalog[i].getLastName()[j];
			else
				std::cout << " ";
		}
		std::cout << "|";

		for (long unsigned int j = 0; j < 10; j++)
		{
			if (j < myCatalog[i].getNickName().length() && j == 9)
				std::cout << ".";
			else if (j < myCatalog[i].getNickName().length())
				std::cout << myCatalog[i].getNickName()[j];
			else
				std::cout << " ";
		}
		std::cout << "\n";
		i++;
	}
}

void	printSpecificContact(PhoneBook myPhoneBook, int index, int maxCurrIndex)
{
	Contact	selectedContact;
	Contact	*myCatalog;

	myCatalog = myPhoneBook.getCatalog();
	if (index == 0)
		std::cout << "This is not a valid index\n";
	else if (index > maxCurrIndex || index > 8)
		std::cout << "Index: " + SSTR(index) + " is not a valid index\n";
	else
	{
		selectedContact = myCatalog[index - 1];
		std::cout << "First name: " + selectedContact.getFirstName() << std::endl;
		std::cout << "Last name: " + selectedContact.getLastName() << std::endl;
		std::cout << "Nick name: " + selectedContact.getNickName() << std::endl;
		std::cout << "Phone number: " + selectedContact.getPhoneNumber() << std::endl;
		std::cout << "Darkest secret: " + selectedContact.getDarkestSecret() << std::endl;
	}
}

void	executeSearch(PhoneBook myPhoneBook, int currentMaxIndex)
{
	std::string	selected_index_str;
	int		selected_index;
	std::stringstream ss;

	printContacts(myPhoneBook);
	std::cout << "Give the index of the Contact you wanna see\n";
	std::getline(std::cin, selected_index_str);
	ss << selected_index_str;
	ss >> selected_index; 
	printSpecificContact(myPhoneBook, selected_index, currentMaxIndex);
}

void	executeAdd(int &index, PhoneBook &phoneBook)
{
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;
	Contact	newContact;

	do{
		std::cout << "Give your first name: ";
		std::getline(std::cin, firstName);
		if (firstName.empty())
			std::cout << "This field shouldn't be empty\n";
	} while (firstName.empty());
	
	do{
		std::cout << "\nGive your last name: ";
		std::getline(std::cin, lastName);
		if (lastName.empty())
			std::cout << "This field shouldn't be empty\n";
	} while (lastName.empty());

	do{
		std::cout << "\nGive your nickName: ";
		std::getline(std::cin, nickName);
		if (nickName.empty())
			std::cout << "This field shouldn't be empty\n";
	} while (nickName.empty());
	
	do{
		std::cout << "\nGive your phone number: ";
		std::getline(std::cin, phoneNumber);
		if (phoneNumber.empty())
			std::cout << "This field shouldn't be empty\n";
	} while (phoneNumber.empty());

	do{
		std::cout << "\nGive your darkest secret: ";
		std::getline(std::cin, darkestSecret);
		if (darkestSecret.empty())
			std::cout << "This field shouldn't be empty\n";
	} while (darkestSecret.empty());

	std::cout << "\n";

	newContact = createContact(firstName, lastName, nickName, phoneNumber, darkestSecret);
	addContact(newContact, phoneBook, index); 
}

int main()
{
	PhoneBook	myPhoneBook;
	Contact		myContact;
	int			index;
	std::string		command;

	index = 0;
	std::cout << "Welcome to the phoneBook!\n";
	std::cout << "Available commands:\n";
	std::cout << "ADD: adding a new Contact to the phoneBook\n";
	std::cout << "SEARCH: display a specific contact\n";
	std::cout << "EXIT: to terminate the program\n";

	while (1)
	{
		std::cout << "Give a command: ";
		std::getline(std::cin, command);
		if (std::cin.eof())
			exit(1);
		if (command == "EXIT")
			break;
		else if (command == "ADD")
			executeAdd(index, myPhoneBook);
		else if (command == "SEARCH")
			executeSearch(myPhoneBook, index);
		else
			std::cout << "Command: " + command + " is not acceptable!\n";

	}

	return 0;
}
