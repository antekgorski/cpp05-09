// Copyright 2025 Antoni Gorski
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 10:43:21 by agorski           #+#    #+#             */
/*   Updated: 2025/07/07 18:06:54 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include <ctime>
#include <cstdlib>

int main() {
    Intern intern;
    Bureaucrat bureaucrat("John", 1);
    AForm *form;
    std::srand(static_cast<unsigned int>(std::time(0))); // Seed for random number generation
    try {
        form = intern.makeForm("PresidentialPardonForm", "Alice");
        bureaucrat.signForm(*form);
        bureaucrat.executeForm(*form);
        delete form;

        form = intern.makeForm("RobotomyRequestForm", "Bob");
        bureaucrat.signForm(*form);
        bureaucrat.executeForm(*form);
        delete form;

        form = intern.makeForm("ShrubberyCreationForm", "Charlie");
        bureaucrat.signForm(*form);
        bureaucrat.executeForm(*form);
        delete form;

        // Attempt to create a non-existent form
        form = intern.makeForm("NonExistentForm", "Dave");
        delete form; // This line should not be reached
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}
