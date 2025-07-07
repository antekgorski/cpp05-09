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

#include "/Bureaucrat.hpp"
#include "/AForm.hpp"

int main() {
// CONSTRUCTOR TEST
std::cout << "constructor test" << std::endl;

try {
        Bureaucrat test1("test1", 129);
        std::cout<< "Constructor value ok: " << test1;
    }

catch (std::exception & e) {
        std::cout << "Exception cath Constructor value out of range: "
        std::cout << e.what() << std::endl;
    }

// COPY INCREMENT TEST
std::cout << std::endl << "Increment test" << std::endl;

try {
        Bureaucrat test2("test2", 10);
        std::cout << "Before increment: " << test2;
        test2.Increment();
        std::cout << "After increment: " << test2;
    }

catch (std::exception & e) {
        std::cout << "Exception cath Increment value out of range: "
        std::cout << e.what() << std::endl;
    }
// DECREMENT TEST
std::cout << std::endl << "Decrement test" << std::endl;

try {
        Bureaucrat test3("test3", 149);
        std::cout << "Before decrement: " << test3;
        test3.Decrement();
        std::cout << "After decrement: " << test3;
    }

catch (std::exception & e) {
        std::cout << "Exception cath Decrement value out of range: "
        std::cout << e.what() << std::endl;
    }

// FORM TEST
std::cout << std::endl << "Form test" << std::endl;

        Bureaucrat robocop("robocop", 51);
        // AForm autodestruction("autodestruction", 50, 50);
        std::cout << "Bureaucrat: " << robocop << std::endl;
        // std::cout << "Form: " << autodestruction << std::endl;
        // robocop.signForm(autodestruction);
        // std::cout << "Form after signing: " << autodestruction << std::endl;
        robocop.Increment();
        robocop.Increment();
        // robocop.signForm(autodestruction);
        // std::cout << "Form after signing: " << autodestruction << std::endl;
}
