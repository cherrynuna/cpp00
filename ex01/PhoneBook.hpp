#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact		contacts[8];

		int	cur;
		int	cnt;

	public:
		PhoneBook() : cur(0), cnt(0) {}

		int getCnt() const { return cnt; }

		struct IsNotPrintable
		{
			bool operator()(unsigned char c) const 
			{
				return !std::isprint(c);  // 출력 불가능한 문자인 경우 true 반환
			}
		};

		void	addContact()
		{
			Contact	newContact;
			std::string	input;
			
			std::cout << "Enter name: ";
			std::getline(std::cin, input);
			input.erase(std::remove_if(input.begin(), input.end(), IsNotPrintable()), input.end());
			newContact.setName(input);
			std::cout << "Enter surname: ";
			std::getline(std::cin, input);
			input.erase(std::remove_if(input.begin(), input.end(), IsNotPrintable()), input.end());
			newContact.setSurname(input);
			std::cout << "Enter nickname: ";
			std::getline(std::cin, input);
			input.erase(std::remove_if(input.begin(), input.end(), IsNotPrintable()), input.end());
			newContact.setNickname(input);
			while (1)
			{
				std::cout << "Enter phone number: ";
				std::getline(std::cin, input);
				if (std::all_of(input.begin(), input.end(), ::isdigit))
					break;
				else
					std::cout << "Please enter onlydigits (0-9).\n";
			}
			newContact.setPhone(input);
			std::cout << "Enter darkest secret: ";
			std::getline(std::cin, input);
			input.erase(std::remove_if(input.begin(), input.end(), IsNotPrintable()), input.end());
			newContact.setSecret(input);

			if (std::cin.eof()){
				std::cout << "\nADD cancelled" << std::endl;
				return ;
			}
			contacts[cur] = newContact;
			cnt++;
			cur = (cur + 1) % 8;
		}

		std::string TenChar(const std::string &str) const
		{
			std::string result = str;

			if (result.length() > 10)
				return result.substr(0, 9) + ".";

			return result;
		}

		void	ShowContacts() const
		{
			std::cout << std::setw(10) << "Index" << "|"
					  << std::setw(10) << "First Name" << "|"
					  << std::setw(10) << "Last Name" << "|"
					  << std::setw(10) << "Nickname" << std::endl;
			std::cout << "-------------------------------------------" << std::endl;
			for (int i = 0; i < 8 && i < cnt; ++i)
			{
				std::cout << std::setw(10) << i + 1 << "|"
						  << std::setw(10) << TenChar(contacts[i].getName()) << "|"
						  << std::setw(10) << TenChar(contacts[i].getSurname()) << "|"
						  << std::setw(10) << TenChar(contacts[i].getNickname()) << std::endl;
			}
		}

		void	ShowInfo(int i) const
		{
			std::cout << std::endl;
			std::cout << "first name: " << contacts[i].getName() << std::endl;
			std::cout << "last name: " << contacts[i].getSurname() << std::endl;
			std::cout << "nickname: " << contacts[i].getNickname() << std::endl;
			std::cout << "phone: " << contacts[i].getPhone() << std::endl;
			std::cout << "darkest secret: " << contacts[i].getSecret() << std::endl;
			std::cout << std::endl;
		}
};

#endif