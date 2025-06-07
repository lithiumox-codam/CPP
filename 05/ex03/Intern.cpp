#include "Intern.hpp"

#include <iostream>

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() { std::cout << "Intern default Constructor called" << std::endl; }

Intern::~Intern() { std::cout << "Intern Destructor called" << std::endl; }

Intern &Intern::operator=(const Intern &obj) {
	std::cout << "Intern Assignment Operator called" << std::endl;
	if (this == &obj) return *this;
	return *this;
}

Intern::Intern(const Intern &obj) {
	std::cout << "Intern Copy Constructor called" << std::endl;
	*this = obj;
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) const {
	auto createShrubbery = [](const std::string &target) -> AForm * { return new ShrubberyCreationForm(target); };
	auto createRobotomy = [](const std::string &target) -> AForm * { return new RobotomyRequestForm(target); };
	auto createPresidential = [](const std::string &target) -> AForm * { return new PresidentialPardonForm(target); };

	std::string formTypes[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm *(*formCreators[3])(const std::string &) = {createShrubbery, createRobotomy, createPresidential};

	for (int i = 0; i < 3; i++) {
		if (formName == formTypes[i]) {
			std::cout << "Intern creates " << formName << " form" << std::endl;
			return formCreators[i](target);
		}
	}

	std::cout << "Intern cannot create form: " << formName << std::endl;
	return nullptr;
}
