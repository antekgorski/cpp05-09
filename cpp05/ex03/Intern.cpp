/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 16:50:33 by agorski           #+#    #+#             */
/*   Updated: 2025/07/13 17:28:01 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other) {
    (void)other; // To avoid unused parameter warning
}

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &other) {
    (void)other; // To avoid unused parameter warning
    return *this;
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) const {
    std::string formNames[] = {
        "PresidentialPardonForm",
        "RobotomyRequestForm",
        "ShrubberyCreationForm"
    };

    for (int i = 0; i < 3; i++) {
        if (formNames[i] == formName) {
            switch (i) {
                case 0: return new PresidentialPardonForm(target);
                case 1: return new RobotomyRequestForm(target);
                case 2: return new ShrubberyCreationForm(target);
            }
        }
    }

    throw FormNotFoundException();
}

const char *Intern::FormNotFoundException::what() const throw() {
    return "Form not found!";
}
