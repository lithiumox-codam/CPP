#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute, std::string target)
    : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _target(target) {
    if (gradeToSign < 1 || gradeToExecute < 1) {
        throw GradeTooHighException();
    }
    if (gradeToSign > 150 || gradeToExecute > 150) {
        throw GradeTooLowException();
    }
}

AForm::AForm(const AForm& other) : _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute), _target(other._target) {}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        _signed = other.isSigned();
    }
    return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const {
    return _name;
}

bool AForm::isSigned() const {
    return _signed;
}

int AForm::getGradeToSign() const {
    return _gradeToSign;
}

int AForm::getGradeToExecute() const {
    return _gradeToExecute;
}

std::string AForm::getTarget() const {
    return _target;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() <= _gradeToSign) {
        _signed = true;
    } else {
        throw GradeTooLowException();
    }
}

void AForm::checkExecutability(const Bureaucrat& executor) const {
    if (!_signed) {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > _gradeToExecute) {
        throw GradeTooLowException();
    }
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed!";
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << "Form: " << form.getName()
       << ", Signed: " << (form.isSigned() ? "Yes" : "No")
       << ", Grade to Sign: " << form.getGradeToSign()
       << ", Grade to Execute: " << form.getGradeToExecute();
    return os;
}
