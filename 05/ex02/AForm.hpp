#pragma once

#include <iostream>
#include <string>

class Bureaucrat;

class AForm {
   private:
	const std::string _name;
	bool _signed;
	const int _gradeToSign;
	const int _gradeToExecute;
	std::string _target;

   public:
	AForm();
	AForm(std::string name, int gradeToSign, int gradeToExecute, std::string target);
	virtual ~AForm();
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);

	std::string getName() const;
	bool isSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	std::string getTarget() const;
	void beSigned(const Bureaucrat& bureaucrat);
	void checkExecutability(const Bureaucrat& executor) const;
	virtual void execute(const Bureaucrat& executor) const = 0;

	class GradeTooHighException : public std::exception {
	   public:
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
	   public:
		virtual const char* what() const throw();
	};
	class FormNotSignedException : public std::exception {
	   public:
		virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const AForm& form);
