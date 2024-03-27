#pragma once
#ifndef __HARL_H__
#define __HARL_H__
#include <string>

class Harl {
   public:
	Harl();
	~Harl();
	Harl& operator=(const Harl& other);
	void complain(std::string level);

   private:
	void debug();
	void info();
	void warning();
	void error();
};

typedef void (Harl::*HarlFunc)();

#endif
