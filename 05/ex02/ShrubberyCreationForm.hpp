#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
   public:
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	~ShrubberyCreationForm();
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

	virtual void execute(const Bureaucrat& executor) const;
};
