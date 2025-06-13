/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    ShrubberyCreationForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:26:22 by agorski           #+#    #+#             */
/*   Updated: 2025/06/13 18:41:47 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class  ShrubberyCreationForm
{
private:
    virtual void FormAction() const; // Implementation of the pure virtual function from AForm.
    const std::string Target_;
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string &target);
    ShrubberyCreationForm(const ShrubberyCreationForm &other);
    ~ ShrubberyCreationForm();
};

#endif
