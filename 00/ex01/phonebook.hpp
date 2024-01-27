#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>

class Contact {
   private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string darkest_secret;
	std::string phone_number;

   public:
	void set_first_name(std::string first_name) { this->first_name = first_name; };
	void set_last_name(std::string last_name) { this->last_name = last_name; };
	void set_nickname(std::string nickname) { this->nickname = nickname; };
	void set_darkest_secret(std::string darkest_secret) { this->darkest_secret = darkest_secret; };
	void set_phone_number(std::string phone_number) { this->phone_number = phone_number; };
	std::string get_first_name() { return this->first_name; };
	std::string get_last_name() { return this->last_name; };
	std::string get_nickname() { return this->nickname; };
	std::string get_darkest_secret() { return this->darkest_secret; };
	std::string get_phone_number() { return this->phone_number; };
};

class PhoneBook {
   private:
	Contact contacts[8];
	int contact_count;

   public:
	PhoneBook() { contact_count = 0; };
	void add_contact();
	void search_contact();
	void print_contact(int index);
};

#endif	// PHONEBOOK_HPP
