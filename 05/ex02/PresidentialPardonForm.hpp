#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
   public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	~PresidentialPardonForm();
	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

	virtual void execute(const Bureaucrat& executor) const;
};
