/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:22:26 by agorski           #+#    #+#             */
/*   Updated: 2025/05/28 14:27:12 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : Name_("Default"), Signed_(false), GradeToSign_(75), GradeToExecute_(75) {}

Form::Form(std::string Name, int GradeToSign, int GradeToExecute)
    : Name_(Name), Signed_(false), GradeToSign_(GradeToSign), GradeToExecute_(GradeToExecute)
{
    if (GradeToSign < 1 || GradeToExecute < 1)
        throw Form::GradeTooHighException();
    if (GradeToSign > 150 || GradeToExecute > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form &other)
    : Name_(other.Name_), Signed_(other.Signed_), GradeToSign_(other.GradeToSign_), GradeToExecute_(other.GradeToExecute_) {}

Form::~Form() {}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Form grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Form grade is too low!";
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->getGradeToSign())
        throw Form::GradeTooHighException();
    else
        this->setSigned(true);
    std::cout << bureaucrat.getName() << " signed " << this->getName() << "Form" << std::endl;
}

const std::string &Form::getName() const
{
    return Name_;
}

const bool &Form::getSigned() const
{
    return Signed_;
}

const int &Form::getGradeToSign() const
{
    return GradeToSign_;
}

const int &Form::getGradeToExecute() const
{
    return GradeToExecute_;
}

void Form::setSigned(bool signedStatus)
{
    Signed_ = signedStatus;
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
    os << "Form Name: " << form.getName()
       << ", Signed: " << (form.getSigned() ? "Yes" : "No")
       << ", Grade to Sign: " << form.getGradeToSign()
       << ", Grade to Execute: " << form.getGradeToExecute();
    return os;
}