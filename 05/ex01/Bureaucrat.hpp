#pragma once

#include <iostream>
#include <string>

#include "Form.hpp"

class Bureaucrat {
   private:
	std::string const _name;
	int _grade;

   public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);

	std::string getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();
	void signForm(Form& form);

	class GradeTooHighException : public std::exception {
	   public:
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
	   public:
		virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
