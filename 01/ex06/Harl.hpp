#pragma once

#include <string>

#define BLUE "\033[34m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RED "\033[31m"
#define TEAL "\033[36m"
#define RESET "\033[0m"

class Harl {
   public:
	Harl();
	~Harl();
	void complain(std::string level);

   private:
	void debug();
	void info();
	void warning();
	void error();
};

typedef void (Harl::*HarlFunc)();
