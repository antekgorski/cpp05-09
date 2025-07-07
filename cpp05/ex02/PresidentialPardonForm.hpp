// Copyright 2025 Antoni Gorski
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:27:45 by agorski           #+#    #+#             */
/*   Updated: 2025/06/13 18:46:36 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP05_EX02_PRESIDENTIALPARDONFORM_HPP_
#define CPP05_EX02_PRESIDENTIALPARDONFORM_HPP_

#include <string>
#include "/AForm.hpp"

class PresidentialPardonForm {
 private:
// Implementation of the pure virtual function from AForm.
    virtual void FormAction() const;
    const std::string Target_;
    PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
 public:
    PresidentialPardonForm();
    explicit PresidentialPardonForm(const std::string &target);
    PresidentialPardonForm(const PresidentialPardonForm &other);
    ~PresidentialPardonForm();
};

#endif  // CPP05_EX02_PRESIDENTIALPARDONFORM_HPP_
