/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:22:47 by agorski           #+#    #+#             */
/*   Updated: 2025/05/27 14:34:59 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Form
{
    private:
        const std::string Name_;
        bool Signed_;
        const int GradeToSign_;
        const int GradeToExecute_;
        Form& operator=(const Form& other);//block becouse i have const...
        
    public:
        Form();
        Form(std::string Name, int GradeToSign, int GradeToExecute);
        Form(const Form& other);
        ~Form();
        
        void beSigned(Bureaucrat& bureaucrat);

        class GradeTooHighException : public std::exception
            {
                public:
                    virtual const char* what() const throw();
            };
        class GradeTooLowException : public std::exception
            {
                public:
                    virtual const char* what() const throw();
            };
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif