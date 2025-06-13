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

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
    virtual void FormAction() const; // Implementation of the pure virtual function from AForm.
    const std::string Target_;
    RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
    public:
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string &target);
    RobotomyRequestForm(const RobotomyRequestForm &other);
    ~RobotomyRequestForm();  
};

#endif