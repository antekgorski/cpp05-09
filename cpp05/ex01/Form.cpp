/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:22:26 by agorski           #+#    #+#             */
/*   Updated: 2025/05/27 14:59:10 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : Name_("Default"), Signed_(false), GradeToSign_(75), GradeToExecute_(75) {}

Form::Form(std::string Name, int GradeToSign, int GradeToExecute) 
    : Name_(Name), Signed_(false), GradeToSign_(GradeToSign), GradeToExecute_(GradeToExecute) 
{
    if (GradeToSign < 1 || GradeToExecute < 1)
        throw Form::GradeTooHighException();
    if (GradeToSign > 150 || GradeToExecute > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form& other) 
    : Name_(other.Name_), Signed_(other.Signed_), GradeToSign_(other.GradeToSign_), GradeToExecute_(other.GradeToExecute_) {}

Form::~Form() {}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Form grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form grade is too low!";
}

void Form::beSigned(Bureaucrat& bureaucrat)
{
    
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os << "Form Name: " << form.Name_ 
       << ", Signed: " << (form.Signed_ ? "Yes" : "No") 
       << ", Grade to Sign: " << form.GradeToSign_ 
       << ", Grade to Execute: " << form.GradeToExecute_;
    return os;
}