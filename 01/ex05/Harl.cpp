#include "Harl.hpp"

#include <iostream>

Harl::Harl() {}

Harl::~Harl() {}

void Harl::complain(std::string level) {
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	HarlFunc functions[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < 4; i++)
		if (level == levels[i]) return (this->*functions[i])();

	std::cout << TEAL << "I don't know what to do with this level of complaint. "
			  << "I might just quit while im ahead cheerio!" << RESET << std::endl;
}

void Harl::debug() {
	std::cout << BLUE
			  << "Oh, you've summoned me to debug, have you? Brace yourself "
				 "for a wild ride through the mystical "
				 "realm of code mysteries and unexpected surprises. Get ready "
				 "for the most thrilling rollercoaster of "
				 "excitement and disappointment you never knew you needed."
			  << RESET << std::endl;
}

void Harl::info() {
	std::cout << GREEN
			  << "Ah, seeking enlightenment from yours truly, I see. Here's "
				 "some info for you because "
				 "clearly, the "
				 "universe revolves around your need for my enlightening "
				 "wisdom. Prepare to have your mind blown – or "
				 "at least mildly stirred."
			  << RESET << std::endl;
}

void Harl::warning() {
	std::cout << YELLOW
			  << "An impending disaster is looming on the horizon. Just "
				 "kidding, or am I? Buckle up, "
				 "buttercup! Your journey through the treacherous lands of "
				 "\"I-totally-saw-that-coming\" is about to begin."
			  << RESET << std::endl;
}

void Harl::error() {
	std::cout << RED
			  << "Oh no, an error! Your code seems to be having a little "
				 "existential crisis. Don't panic; "
				 "it's just trying to find its purpose in this vast sea of "
				 "algorithms and logic. Remember, even the "
				 "best of us have our moments of self-doubt and confusion."
			  << RESET << std::endl;
}
