/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:22:26 by agorski           #+#    #+#             */
/*   Updated: 2025/05/30 14:29:52 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : Name_("Default"), Signed_(false), GradeToSign_(75), GradeToExecute_(75) {}

AForm::AForm(std::string Name, int GradeToSign, int GradeToExecute)
    : Name_(Name), Signed_(false), GradeToSign_(GradeToSign), GradeToExecute_(GradeToExecute)
{
    if (GradeToSign < 1 || GradeToExecute < 1)
        throw AForm::GradeTooHighException();
    if (GradeToSign > 150 || GradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other)
    : Name_(other.Name_), Signed_(other.Signed_), GradeToSign_(other.GradeToSign_), GradeToExecute_(other.GradeToExecute_) {}

AForm::~AForm() {}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Form grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Form grade is too low!";
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->getGradeToSign())
        throw AForm::GradeTooHighException();
    else
        this->setSigned(true);
    std::cout << bureaucrat.getName() << " signed " << this->getName() << "Form" << std::endl;
}

 void execute(Bureaucrat const & executor) const
 {
    
 }

const std::string &AForm::getName() const
{
    return Name_;
}

const bool &AForm::getSigned() const
{
    return Signed_;
}

const int &AForm::getGradeToSign() const
{
    return GradeToSign_;
}

const int &AForm::getGradeToExecute() const
{
    return GradeToExecute_;
}

void AForm::setSigned(bool signedStatus)
{
    Signed_ = signedStatus;
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
    os << "Form Name: " << form.getName()
       << ", Signed: " << (form.getSigned() ? "Yes" : "No")
       << ", Grade to Sign: " << form.getGradeToSign()
       << ", Grade to Execute: " << form.getGradeToExecute();
    return os;
}