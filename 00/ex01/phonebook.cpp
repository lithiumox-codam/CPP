#include "phonebook.hpp"

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
			std::getline(std::cin, input);
		} while (input.empty() || !std::all_of(input.begin(), input.end(), ::isdigit));
	} else
		do {
			std::cout << prompt;
			std::getline(std::cin, input);
		} while (input.empty());
	input.erase(0, input.find_first_not_of(' '));
	input.erase(input.find_last_not_of(' ') + 1);
	return input;
}

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
	if (this->contact_count == 0) {
		std::cout << "Phone book is empty." << std::endl;
		return;
	}
	std::cout << std::setw(10) << "Index"
			  << "|";
	std::cout << std::setw(10) << "First name"
			  << "|";
	std::cout << std::setw(10) << "Last name"
			  << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < this->contact_count; i++) {
		std::cout << std::setw(10) << i << "|";
		std::string first_name = this->contacts[i].get_first_name();
		std::string last_name = this->contacts[i].get_last_name();
		std::string nickname = this->contacts[i].get_nickname();
		if (first_name.length() > 10) first_name = first_name.substr(0, 9) + ".";
		if (last_name.length() > 10) last_name = last_name.substr(0, 9) + ".";
		if (nickname.length() > 10) nickname = nickname.substr(0, 9) + ".";
		std::cout << std::setw(10) << first_name << "|";
		std::cout << std::setw(10) << last_name << "|";
		std::cout << std::setw(10) << nickname << std::endl;
	}
	int index;
	while (true) {
		std::cout << "Enter an index: ";
		std::cin >> index;
		if (index >= 0 && index < this->contact_count)
			break;
		else {
			std::cout << "Invalid index." << std::endl;
			continue;
		}
	}
	this->print_contact(index);
}

void PhoneBook::print_contact(int index) {
	std::cout << " Contact " << index << ":" << std::endl;
	std::cout << "  First name:		" << this->contacts[index].get_first_name() << std::endl;
	std::cout << "  Last name:		" << this->contacts[index].get_last_name() << std::endl;
	std::cout << "  Nickname:		" << this->contacts[index].get_nickname() << std::endl;
	std::cout << "  Darkest secret:	" << this->contacts[index].get_darkest_secret() << std::endl;
	std::cout << "  Phone number: 	" << this->contacts[index].get_phone_number() << std::endl;
}

int main() {
	PhoneBook phonebook;
	std::string command;

	while (true) {
		std::cout << "Enter a command: ";
		std::cin >> command;
		if (command == "EXIT")
			break;
		else if (command == "ADD")
			phonebook.add_contact();
		else if (command == "SEARCH")
			phonebook.search_contact();
		else

			std::cout << "Invalid command." << std::endl;
	}
	return 0;
}
