#include "RobotomyRequestForm.hpp"

#include <cstdlib>
#include <ctime>

#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45, target) {
	std::srand(std::time(0));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	AForm::operator=(other);
	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	checkExecutability(executor);

	std::cout << "* DRILLING NOISES *" << std::endl;
	if (std::rand() % 2) {
		std::cout << getTarget() << " has been robotomized successfully!" << std::endl;
	} else {
		std::cout << "Robotomy failed for " << getTarget() << "." << std::endl;
	}
}
