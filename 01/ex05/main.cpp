#include <iostream>

#include "Harl.hpp"

int main(int ac, char **av) {
	Harl harl;

	if (ac == 2)
		harl.complain(av[1]);
	else {
		std::cerr << "Usage: " << av[0] << " <complaint>" << std::endl;
		return 1;
	}

	return 0;
}
