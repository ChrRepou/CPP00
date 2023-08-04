#ifndef CONTACT_H
#define CONTACT_H

#include <sstream>

class Contact
{
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	phoneNumber;
		std::string	darkestSecret;

	public:
		void setFirstName(std::string firstName);
		std::string	getFirstName(void);

		void setLastName(std::string lastName);
		std::string	getLastName(void);

		void	setNickName(std::string nickName);
		std::string	getNickName(void);

		void	setPhoneNumber(std::string phoneNumber);
		std::string	getPhoneNumber(void);

		void	setDarkestSecret(std::string darkestSecret);
		std::string getDarkestSecret(void);
};

Contact	createContact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret);

#endif