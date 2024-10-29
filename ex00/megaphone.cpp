#include <iostream>
#include <cctype>

void	megaphone(char *av)
{
	for (int i = 0; av[i] != '\0'; i++)
	{
		std::cout << static_cast<char>(std::toupper(av[i]));
	}
}

int	main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < ac; i++)
			megaphone(av[i]);
	}
	std::cout << std::endl;
	return (0);
}
