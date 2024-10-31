#include "PhoneBook.hpp"

// Constructor
PhoneBook::PhoneBook() : cur(0), cnt(0) {}

// Getter for count
int PhoneBook::getCnt() const {
	return cnt;
}

// Replace non-printable characters with a space
void PhoneBook::replaceNonPrintableWithSpace(std::string& input) {
	for (std::string::iterator it = input.begin(); it != input.end(); ++it) {
		if (!std::isprint(static_cast<unsigned char>(*it))) 
			*it = ' ';
	}
}

// Check if all characters in a string are digits
bool PhoneBook::isAllDigits(const std::string& input) {
	for (std::string::const_iterator it = input.begin(); it != input.end(); ++it) {
		if (!std::isdigit(static_cast<unsigned char>(*it)))
			return false;
	}
	return true;
}

// Add a contact to the PhoneBook
void PhoneBook::addContact() {
	Contact newContact;
	std::string input;

	std::cout << "Enter name: ";
	std::getline(std::cin, input);
	replaceNonPrintableWithSpace(input);
	newContact.setName(input);

	std::cout << "Enter surname: ";
	std::getline(std::cin, input);
	replaceNonPrintableWithSpace(input);
	newContact.setSurname(input);

	std::cout << "Enter nickname: ";
	std::getline(std::cin, input);
	replaceNonPrintableWithSpace(input);
	newContact.setNickname(input);

	while (1) {
		std::cout << "Enter phone number: ";
		std::getline(std::cin, input);
		if (isAllDigits(input))
			break;
		else
			std::cout << "Please enter only digits (0-9).\n";
	}
	newContact.setPhone(input);

	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, input);
	replaceNonPrintableWithSpace(input);
	newContact.setSecret(input);

	if (std::cin.eof()) {
		std::cout << "\nADD cancelled" << std::endl;
		return;
	}

	contacts[cur] = newContact;
	cnt++;
	cur = (cur + 1) % 8;
}

// Display a truncated version of a string (10 characters)
std::string PhoneBook::TenChar(const std::string &str) const {
	std::string result = str;
	if (result.length() > 10)
		return result.substr(0, 9) + ".";
	return result;
}

// Display contacts list
void PhoneBook::ShowContacts() const {
	std::cout << std::setw(10) << "Index" << "|"
			  << std::setw(10) << "First Name" << "|"
			  << std::setw(10) << "Last Name" << "|"
			  << std::setw(10) << "Nickname" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;

	for (int i = 0; i < 8 && i < cnt; ++i) {
		std::cout << std::setw(10) << i + 1 << "|"
				  << std::setw(10) << TenChar(contacts[i].getName()) << "|"
				  << std::setw(10) << TenChar(contacts[i].getSurname()) << "|"
				  << std::setw(10) << TenChar(contacts[i].getNickname()) << std::endl;
	}
}

// Show detailed info for a specific contact
void PhoneBook::ShowInfo(int i) const {
	std::cout << std::endl;
	std::cout << "first name: " << contacts[i].getName() << std::endl;
	std::cout << "last name: " << contacts[i].getSurname() << std::endl;
	std::cout << "nickname: " << contacts[i].getNickname() << std::endl;
	std::cout << "phone: " << contacts[i].getPhone() << std::endl;
	std::cout << "darkest secret: " << contacts[i].getSecret() << std::endl;
	std::cout << std::endl;
}