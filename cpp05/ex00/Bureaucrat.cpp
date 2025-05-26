/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 10:44:04 by agorski           #+#    #+#             */
/*   Updated: 2025/05/26 18:42:09 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : Name_("Default"), Grade_(75) {}

Bureaucrat::Bureaucrat(std::string Name, int Grade) : Name_(Name), Grade_(Grade)
{
    //exeption
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : Name_(other.Name_), Grade_(other.Grade_) {}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName()
{
    return (Name_);    
}

int Bureaucrat::getGrade()
{
    return (Grade_);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& Bureaucrat)
{
    
}
