#include "../includes/phonebook.hpp"

#include <cstdlib>
#include <iomanip>
#include <iostream>

/**
 * @brief Constructor for the Contact class.
 */
PhoneBook::PhoneBook() { contact_count = 0; };

/**
 * @brief Checks if a string is all numbers.
 * @param str The string to check.
 * @return bool Whether or not the string is all numbers.
 */
bool is_all_num(std::string &str) {
	bool is_num = true;

	for (unsigned long i = 0; i < str.length(); i++) {
		if (!isdigit(str[i])) {
			is_num = false;
			break;
		}
	}
	return is_num;
}

bool protect_gl(std::string &str) {
	if (!std::getline(std::cin, str))
		std::exit(0);
	else if (str.empty())
		return false;
	return true;
}

/**
 * @brief Gets the input from the user.
 *
 * @param prompt The prompt to display to the user.
 * @param is_number Whether or not the input should be a number.
 * @param first Whether or not this is the first time the function is called.
 */
std::string get_input(std::string prompt, bool is_number = false, bool first = true) {
	std::string input;
	if (first) std::cin.ignore();
	if (is_number) {
		do {
			std::cout << prompt;
			protect_gl(input);
		} while (input.empty() || !is_all_num(input));
	} else
		do {
			std::cout << prompt;
			protect_gl(input);
		} while (input.empty());
	input.erase(0, input.find_first_not_of(' '));
	input.erase(input.find_last_not_of(' ') + 1);
	return input;
}

/**
 * @brief Adds a contact to the phone book. By default, the contact is added to the first available slot. If there are
 * no available slots, the oldest contact is removed and the new contact is added to the last slot.
 */
void PhoneBook::add_contact() {
	Contact contact;

	contact.set_first_name(get_input("Enter first name: ", false, true));
	contact.set_last_name(get_input("Enter last name: ", false, false));
	contact.set_nickname(get_input("Enter nickname: ", false, false));
	contact.set_darkest_secret(get_input("Enter darkest secret: ", false, false));
	contact.set_phone_number(get_input("Enter phone number: ", true, false));
	if (this->contact_count < 8) {
		this->contacts[this->contact_count] = contact;
		this->contact_count++;
	} else {
		for (int i = 0; i < 7; i++) {
			this->contacts[i] = this->contacts[i + 1];
		}
		this->contacts[7] = contact;
	}
}

void PhoneBook::search_contact() {
	const int width = 10;
	const int max_w = 9;
	if (this->contact_count == 0) {
		std::cout << "Phone book is empty."
				  << "\n";
		return;
	}
	std::cout << std::setw(width) << "Index"
			  << "|";
	std::cout << std::setw(width) << "First name"
			  << "|";
	std::cout << std::setw(width) << "Last name"
			  << "|";
	std::cout << std::setw(width) << "Nickname"
			  << "\n";
	for (int i = 0; i < this->contact_count; i++) {
		std::cout << std::setw(width) << i << "|";
		std::string first_name = this->contacts[i].get_first_name();
		std::string last_name = this->contacts[i].get_last_name();
		std::string nickname = this->contacts[i].get_nickname();
		if (first_name.length() > width) {
			first_name = first_name.substr(0, max_w) + ".";
		}
		if (last_name.length() > width) {
			last_name = last_name.substr(0, max_w) + ".";
		}
		if (nickname.length() > width) {
			nickname = nickname.substr(0, max_w) + ".";
		}
		std::cout << std::setw(width) << first_name << "|";
		std::cout << std::setw(width) << last_name << "|";
		std::cout << std::setw(width) << nickname << "\n";
	}
	int index = 0;
	while (true) {
		std::cout << "Enter an index: ";
		std::cin >> index;
		if (index >= 0 && index < this->contact_count) {
			break;
		} else {
			std::cout << "Invalid index."
					  << "\n";
			continue;
		}
	}
	this->print_contact(index);
}

/**
 * @brief Prints a contact to the console.
 * @param index The index of the contact to print.
 */
void PhoneBook::print_contact(int index) {
	std::cout << " Contact " << index << ":"
			  << "\n";
	std::cout << "  First name:		" << this->contacts[index].get_first_name() << "\n";
	std::cout << "  Last name:		" << this->contacts[index].get_last_name() << "\n";
	std::cout << "  Nickname:		" << this->contacts[index].get_nickname() << "\n";
	std::cout << "  Darkest secret:	" << this->contacts[index].get_darkest_secret() << "\n";
	std::cout << "  Phone number: 	" << this->contacts[index].get_phone_number() << "\n";
}

int main() {
	PhoneBook phonebook;
	std::string command;

	while (true) {
		std::cout << "Enter a command: ";
		protect_gl(command);
		if (command == "ADD") {
			phonebook.add_contact();
		} else if (command == "SEARCH") {
			phonebook.search_contact();
		} else if (command == "EXIT") {
			break;
		} else {
			std::cout << "Invalid command."
					  << "\n";
		}
	}
	return 0;
}
