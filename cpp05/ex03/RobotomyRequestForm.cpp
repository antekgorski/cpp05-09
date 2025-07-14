// Copyright 2025 Antoni Gorski
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 18:47:05 by agorski           #+#    #+#             */
/*   Updated: 2025/06/13 18:54:31 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("Default", 72, 45), Target_("Default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45), Target_(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other),
      Target_(other.Target_) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::FormAction() const {
    if (std::rand() % 2) {
        std::cout << Target_ << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << Target_ <<  " Robotomy failed." << std::endl;
    }
}
