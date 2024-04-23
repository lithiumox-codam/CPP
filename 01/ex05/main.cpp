#include <iostream>

#include "Harl.hpp"

int main(int ac, char **av) {
	if (ac != 2) return 1;
	Harl harl;
	harl.complain(av[1]);

	// std::cout << std::endl << "To show all of them work:" << std::endl;
	// harl.complain("DEBUG");
	// harl.complain("INFO");
	// harl.complain("WARNING");
	// harl.complain("ERROR");
	return 0;
}
