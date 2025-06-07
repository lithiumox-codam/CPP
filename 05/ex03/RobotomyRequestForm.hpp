#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
   public:
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	~RobotomyRequestForm();
	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

	virtual void execute(const Bureaucrat& executor) const;
};
