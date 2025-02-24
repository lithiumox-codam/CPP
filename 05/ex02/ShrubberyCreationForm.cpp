#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("ShrubberyCreationForm", 145, 137, target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    AForm::operator=(other);
    return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    checkExecutability(executor);
    
    std::string filename = getTarget() + "_shrubbery";
    std::ofstream outFile(filename.c_str());
    
    if (!outFile.is_open()) {
        throw std::runtime_error("Cannot create file");
    }
    
    outFile << "      *      " << std::endl;
    outFile << "     ***     " << std::endl;
    outFile << "    *****    " << std::endl;
    outFile << "   *******   " << std::endl;
    outFile << "  *********  " << std::endl;
    outFile << "     |||     " << std::endl;
    outFile.close();
}
