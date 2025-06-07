#pragma once

#include <string>

#include "AForm.hpp"

class Intern {
   public:
	Intern();
	~Intern();
	Intern(const Intern &obj);
	Intern &operator=(const Intern &obj);

	AForm *makeForm(const std::string &formName, const std::string &target) const;
};
