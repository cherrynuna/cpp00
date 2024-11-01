#include "PhoneBook.hpp"

void	showMenu(void)
{
	std::cout << "-----Menu-----"<<std::endl;
	std::cout << "ADD"<<std::endl;
	std::cout << "SEARCH"<<std::endl;
	std::cout << "EXIT"<<std::endl;
}

int	main(void)
{
	std::string	choice;
	PhoneBook	phonebook;

	while (1)
	{
		showMenu();
		std::cout << "choice: ";
		std::getline(std::cin, choice);
		std::cout << std::endl;

		if (choice == "ADD")
			phonebook.addContact();
		else if (choice == "SEARCH" && phonebook.getCnt() > 0)
		{
			phonebook.showContacts();
			while (1)
			{
				std::cout << "choice: ";
				std::getline(std::cin, choice);
				if (choice.size() == 1)
				{
					if ('0' < choice[0] && choice[0] < '9' && choice[0] - 48 <= phonebook.getCnt())
						break ;
					else
						std::cout << "Invalid choice."<<std::endl;
				}
				else
					std::cout << "Invalid input. Please enter a number." << std::endl;
				if (std::cin.eof()){
					clearerr(stdin);
					std::cin.clear();
				}
			}
			phonebook.showInfo(choice[0] - 49);
		}
		else if (choice == "EXIT")
			return (0);
		else
			std::cout<<"Invalid choice."<<std::endl;
		if (std::cin.eof()){
					clearerr(stdin);
					std::cin.clear();
				}
	}
	return (0);
}
