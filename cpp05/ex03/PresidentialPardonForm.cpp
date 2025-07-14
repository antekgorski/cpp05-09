// Copyright 2025 Antoni Gorski
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:27:49 by agorski           #+#    #+#             */
/*   Updated: 2025/06/13 18:54:24 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("Default", 25, 5), Target_("Default") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("PresidentialPardonForm", 25, 5), Target_(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
    : AForm(other),
      Target_(other.Target_) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::FormAction() const {
    std::cout << Target_ << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
