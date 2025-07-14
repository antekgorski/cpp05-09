/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 16:50:29 by agorski           #+#    #+#             */
/*   Updated: 2025/07/13 16:54:00 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP05_EX03_INTERN_HPP_
#define CPP05_EX03_INTERN_HPP_
#include "AForm.hpp"
#include <string>
#include <iostream>

class Intern {
 public:
    Intern();
    Intern(const Intern &other);
    ~Intern();
    Intern &operator=(const Intern &other);

    AForm *makeForm(const std::string &formName, const std::string &target) const;

    class FormNotFoundException : public std::exception {
     public:
        virtual const char *what() const throw();
    };
};

#endif  // CPP05_EX03_INTERN_HPP_