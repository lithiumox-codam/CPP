#include <cctype>
#include <iostream>
#include <string>

/**
 * @brief Main funciton of Megaphone a program that takes a string as argument and prints it in uppercase
 * @param ac Number of arguments
 * @param av Array of arguments
 * @return 0 if everything is ok otherwise 1
 */
int main(int ac, char **av) {
	if (ac == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
		return 0;
	} else {
		for (int i = 1; i < ac; i++) {
			std::string str(av[i]);
			for (char &c : str) {
				c = std::toupper(c);
			}
			if (i == ac - 1)
				std::cout << str;
			else
				std::cout << str + " ";
		}
	}
	std::cout << "\n";
	return 0;
}
