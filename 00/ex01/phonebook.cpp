#include "phonebook.hpp"

PhoneBook::PhoneBook() { this->contact_count = 0; }

void PhoneBook::add_contact() {
  Contact contact;
  std::string first_name;
  std::string last_name;
  std::string nickname;
  std::string darkest_secret;
  std::string phone_number;

  std::cout << "Enter first name: ";
  std::getline(std::cin, first_name);
  contact.set_first_name(first_name);
  std::cout << "Enter last name: ";
  std::getline(std::cin, last_name);
  contact.set_last_name(last_name);
  std::cout << "Enter nickname: ";
  std::getline(std::cin, nickname);
  contact.set_nickname(nickname);
  std::cout << "Enter darkest secret: ";
  std::getline(std::cin, darkest_secret);
  contact.set_darkest_secret(darkest_secret);
  std::cout << "Enter phone number: ";
  std::getline(std::cin, phone_number);
  contact.set_phone_number(phone_number);
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
    std::cout << std::setw(10) << this->contacts[i].get_first_name() << "|";
    std::cout << std::setw(10) << this->contacts[i].get_last_name() << "|";
    std::cout << std::setw(10) << this->contacts[i].get_nickname() << std::endl;
  }
  std::cout << "Enter index: ";
  int index;
  std::cin >> index;
  if (index < 0 || index >= this->contact_count) {
    std::cout << "Invalid index." << std::endl;
    return;
  }
  this->print_contact(index);
}

void PhoneBook::print_contact(int index) {
  std::cout << "First name: " << this->contacts[index].get_first_name()
            << std::endl;
  std::cout << "Last name: " << this->contacts[index].get_last_name()
            << std::endl;
  std::cout << "Nickname: " << this->contacts[index].get_nickname()
            << std::endl;
  std::cout << "Darkest secret: " << this->contacts[index].get_darkest_secret()
            << std::endl;
  std::cout << "Phone number: " << this->contacts[index].get_phone_number()
            << std::endl;
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
