#include "PhoneBook.hpp"

void	ShowMenu(void)
{
	std::cout << "-----Menu-----"<<std::endl;
	std::cout << "ADD"<<std::endl;
	std::cout << "SEARCH"<<std::endl;
	std::cout << "EXIT"<<std::endl;
}

int	main(void)
{
	std::string	choice;
	int			num;
	PhoneBook	phonebook;

	while (1)
	{
		ShowMenu();
		std::cout << "choice: ";
		std::getline(std::cin, choice);
		std::cout << std::endl;

		if (choice == "ADD")
			phonebook.addContact();
		else if (choice == "SEARCH" && phonebook.getCnt() > 0)
		{
			phonebook.ShowContacts();
			while (1)
			{
				std::cout << "choice: ";
				if (std::cin >> num)
				{
					if (0 < num && num < 9 && num <= phonebook.getCnt())
						break ;
					else
						std::cout << "Invalid choice."<<std::endl;
				}
				else
				{
					std::cout << "Invalid input. Please enter a number." << std::endl;
					std::cin.clear();  // cin 상태 플래그를 리셋
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// 버퍼를 비움
				}
				if (std::cin.eof()){
					clearerr(stdin);
					std::cin.clear();
				}
			}
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			phonebook.ShowInfo(num - 1);
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
