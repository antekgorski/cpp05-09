/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:22:47 by agorski           #+#    #+#             */
/*   Updated: 2025/05/28 14:26:42 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>

class Bureaucrat;

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
        
        const std::string& getName() const;
        const bool& getSigned() const;
        const int& getGradeToSign() const;
        const int& getGradeToExecute() const;
        
        void setSigned(bool signedStatus);
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