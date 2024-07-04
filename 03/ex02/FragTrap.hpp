#pragma once

#include <string>

#include "./ClapTrap.hpp"

class FragTrap : public ClapTrap {
   public:
	FragTrap();
	FragTrap(const std::string name);
	FragTrap(const FragTrap &fragTrap);
	virtual ~FragTrap();
	FragTrap &operator=(const FragTrap &fragTrap);

	void highFivesGuys(void);
};
