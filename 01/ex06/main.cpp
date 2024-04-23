#include <iostream>

#include "Harl.hpp"

int main(int ac, char** av) {
	Harl Harl;
	if (ac == 2)
		Harl.complain(av[1]);
	else {
		std::cout << "Usage: ./Harl <complaint>" << std::endl;
		return 1;
	}
	return 0;
}
