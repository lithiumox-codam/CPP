#include "Harl.hpp"

#include <iostream>

Harl::Harl() {}

Harl::~Harl() {}

Harl& Harl::operator=(const Harl& other) { return *this; }

void Harl::complain(std::string level) {
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int i = 0;

	for (; i < 4; i++)
		if (level == levels[i]) break;

	switch (i) {
		case 0:
			std::cout << "[ DEBUG ]" << std::endl;
			Harl::debug();
		case 1:
			std::cout << "[ INFO ]" << std::endl;
			Harl::info();
		case 2:
			std::cout << "[ WARNING ]" << std::endl;
			Harl::warning();
		case 3:
			std::cout << "[ ERROR ]" << std::endl;
			Harl::error();
	}
	if (i == 4) std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

void Harl::debug() {
	std::cout << "Oh, you've summoned me to debug, have you? Brace yourself "
				 "for a wild ride through the mystical "
				 "realm of code mysteries and unexpected surprises. Get ready "
				 "for the most thrilling rollercoaster of "
				 "excitement and disappointment you never knew you needed."
			  << std::endl;
}

void Harl::info() {
	std::cout << "Ah, seeking enlightenment from yours truly, I see. Here's "
				 "some info for you because "
				 "clearly, the "
				 "universe revolves around your need for my enlightening "
				 "wisdom. Prepare to have your mind blown – or "
				 "at least mildly stirred."
			  << std::endl;
}

void Harl::warning() {
	std::cout << "An impending disaster is looming on the horizon. Just "
				 "kidding, or am I? Buckle up, "
				 "buttercup! Your journey through the treacherous lands of "
				 "\"I-totally-saw-that-coming\" is about to begin."
			  << std::endl;
}

void Harl::error() {
	std::cout << "Oh no, an error! Your code seems to be having a little "
				 "existential crisis. Don't panic; "
				 "it's just trying to find its purpose in this vast sea of "
				 "algorithms and logic. Remember, even the "
				 "best of us have our moments of self-doubt and confusion."
			  << std::endl;
}
