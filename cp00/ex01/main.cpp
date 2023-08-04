#include "PhoneBook.hpp"

int main()
{
	PhoneBook	myPhoneBook;
	Contact		myContact;
	int			index;
	std::string		command;

	index = 0;
	std::cout << "Welcome to the phoneBook!\n"
			  << "Available commands:\n"
			  << "ADD: adding a new Contact to the phoneBook\n"
			  << "SEARCH: display a specific contact\n"
			  << "EXIT: to terminate the program\n";

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