#pragma once
#ifndef __HUMAN_B__
#define __HUMAN_B__

#include "Weapon.hpp"

class HumanB {
   private:
	std::string name;
	Weapon* weapon;

   public:
	HumanB();
	explicit HumanB(std::string name);
	~HumanB();
	HumanB& operator=(const HumanB& other);
	void attack();
	void setWeapon(Weapon& weapon);
};

#endif	// !__HUMAN_B__
