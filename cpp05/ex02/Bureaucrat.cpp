/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 10:44:04 by agorski           #+#    #+#             */
/*   Updated: 2025/05/28 17:01:53 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : Name_("Default"), Grade_(75) {}

Bureaucrat::Bureaucrat(std::string Name, int Grade) : Name_(Name)
{
    if (Grade > 150)
        throw Bureaucrat::GradeTooLowException();
    if (Grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else
        Grade_ = Grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : Name_(other.Name_), Grade_(other.Grade_) {}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const
{
    return (Name_);
}

int Bureaucrat::getGrade() const
{
    return (Grade_);
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj)
{
    os << obj.getName() << " bureaucrat grade " << obj.getGrade() << std::endl;
    return os;
}

void Bureaucrat::Increment()
{
    if (--Grade_ < 1)
        throw Bureaucrat::GradeTooHighException();
    std::cout << this->getName() << " incremented to grade " << this->getGrade() << std::endl;
}

void Bureaucrat::Decrement()
{
    if (++Grade_ > 150)
        throw Bureaucrat::GradeTooLowException();
    std::cout << this->getName() << " decremented to grade " << this->getGrade() << std::endl;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade is to High");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade is to Low");
}

void Bureaucrat::signForm(AForm &form)
{
    try
    {
        form.beSigned(*this);
    }
    catch (const std::exception &e)
    {
        std::cout << this->getName() << " could not sign " << form.getName() << " because: " << e.what() << std::endl;
        return;
    }
}
