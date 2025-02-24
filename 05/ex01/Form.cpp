#include "Form.hpp"

#include "Bureaucrat.hpp"

Form::Form() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {}

Form::Form(std::string name, int gradeToSign, int gradeToExecute)
	: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1) throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150) throw Form::GradeTooLowException();
}

Form::~Form() {}

Form::Form(const Form& other)
	: _name(other._name),
	  _signed(other._signed),
	  _gradeToSign(other._gradeToSign),
	  _gradeToExecute(other._gradeToExecute) {}

Form& Form::operator=(const Form& other) {
	if (this != &other) _signed = other._signed;
	return *this;
}

std::string Form::getName() const { return _name; }
bool Form::isSigned() const { return _signed; }
int Form::getGradeToSign() const { return _gradeToSign; }
int Form::getGradeToExecute() const { return _gradeToExecute; }

void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > _gradeToSign) throw Form::GradeTooLowException();
	_signed = true;
}

const char* Form::GradeTooHighException::what() const throw() { return "Grade too high"; }

const char* Form::GradeTooLowException::what() const throw() { return "Grade too low"; }

std::ostream& operator<<(std::ostream& os, const Form& form) {
	os << form.getName() << " form is " << (form.isSigned() ? "signed" : "not signed")
	   << ", grade to sign: " << form.getGradeToSign() << ", grade to execute: " << form.getGradeToExecute();
	return os;
}
