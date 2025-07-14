// Copyright 2025 Antoni Gorski
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 18:47:01 by agorski           #+#    #+#             */
/*   Updated: 2025/06/13 18:53:20 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP05_EX02_ROBOTOMYREQUESTFORM_HPP_
#define CPP05_EX02_ROBOTOMYREQUESTFORM_HPP_

#include <string>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
 private:
// Implementation of the pure virtual function from AForm.
    virtual void FormAction() const;
    const std::string Target_;
    RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

 public:
    RobotomyRequestForm();
    explicit RobotomyRequestForm(const std::string &target);
    RobotomyRequestForm(const RobotomyRequestForm &other);
    ~RobotomyRequestForm();
};

#endif  // CPP05_EX02_ROBOTOMYREQUESTFORM_HPP_
