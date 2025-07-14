// Copyright 2025 Antoni Gorski
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:22:47 by agorski           #+#    #+#             */
/*   Updated: 2025/06/13 19:02:27 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>

class Bureaucrat;

class AForm
{
    private:
        const std::string Name_;
        bool Signed_;
        const int GradeToSign_;
        const int GradeToExecute_;
        virtual void FormAction() const = 0;// pure virtual function, making AForm an abstract class and add action to be defined in derived classes.
        AForm& operator=(const AForm& other);//block becouse i have const...
        
        public:
        AForm();
        AForm(std::string Name, int GradeToSign, int GradeToExecute);
        AForm(const AForm& other);
        virtual ~AForm();
        
        const std::string& getName() const;
        const bool& getSigned() const;
        const int& getGradeToSign() const;
        const int& getGradeToExecute() const;
        
        void setSigned(bool signedStatus);
        void beSigned(Bureaucrat& bureaucrat);
        void execute(Bureaucrat const & executor) const;
        
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
        class IsNoSignedException : public std::exception
            {
                public:
                    virtual const char* what() const throw();
            };
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif