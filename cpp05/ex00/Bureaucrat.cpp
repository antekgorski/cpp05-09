/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 10:44:04 by agorski           #+#    #+#             */
/*   Updated: 2025/05/27 13:20:10 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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

Bureaucrat::Bureaucrat(const Bureaucrat& other) : Name_(other.Name_), Grade_(other.Grade_) {}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const
{
    return (Name_);    
}

int Bureaucrat::getGrade() const
{
    return (Grade_);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
    os << obj.getName() << " bureaucrat grade " << obj.getGrade() << std::endl;
    return os;
}

void Bureaucrat::Increment()
{
    if ( --Grade_ < 1 )
        throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::Decrement()
{
    if ( ++Grade_ > 150 )
        throw Bureaucrat::GradeTooLowException();
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
    {
        return ("Grade is to High");
    }

const char* Bureaucrat::GradeTooLowException::what() const throw()
    {
        return ("Grade is to Low");
    }
