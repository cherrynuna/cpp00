#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <limits>
# include <cstdio>
# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact		contacts[8];

		int	cur;
		int	cnt;

		void replaceNonPrintableWithSpace(std::string& input);
		bool isAllDigits(const std::string& input);
		std::string tenChar(const std::string &str) const;

	public:
		PhoneBook();
		int getCnt() const;

		void addContact();
		void showContacts() const;
		void showInfo(int i) const;
};

#endif
