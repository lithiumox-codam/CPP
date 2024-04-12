#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "./Contact.hpp"

class PhoneBook {
   private:
	Contact contacts[8];
	int contact_count;

   public:
	PhoneBook();
	void add_contact();
	void search_contact();
	void print_contact(int index);
};

#endif	// PHONEBOOK_HPP
