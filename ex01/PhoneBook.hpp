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

	public:
		PhoneBook();
		int getCnt() const;

		// Nested struct for non-printable character detection
		struct IsNotPrintable {
			bool operator()(unsigned char c) const;
		};

		void replaceNonPrintableWithSpace(std::string& input);
		bool isAllDigits(const std::string& input);
		void addContact();
		std::string TenChar(const std::string &str) const;
		void ShowContacts() const;
		void ShowInfo(int i) const;
};

#endif
