#include <cctype>
#include <iostream>
#include <string>

int main(int ac, char **av) {
	if (ac == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
		return 0;
	} else {
		for (int i = 1; i < ac; i++) {
			std::string str(av[i]);
			for (char &c : str) {
				c = std::toupper(static_cast<unsigned char>(c));
			}
			std::cout << str + " ";
		}
	}
	std::cout << std::endl;
	return 0;
}
