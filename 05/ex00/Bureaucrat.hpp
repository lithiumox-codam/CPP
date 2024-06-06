#pragma once

#include <iostream>
#include <string>
// !TODO: Add overload!

class Bureaucrat {
   private:
	std::string const _name;
	int _grade;

   public:
	Bureaucrat(std::string name, int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);

	std::string getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();

	class GradeTooHighException : public std::exception {
	   public:
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
	   public:
		virtual const char* what() const throw();
	};
};
