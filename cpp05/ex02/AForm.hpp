/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:22:47 by agorski           #+#    #+#             */
/*   Updated: 2025/05/30 14:29:30 by agorski          ###   ########.fr       */
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
        AForm& operator=(const AForm& other);//block becouse i have const...
        
        public:
        AForm();
        AForm(std::string Name, int GradeToSign, int GradeToExecute);
        AForm(const AForm& other);
        ~AForm();

        virtual void abstract() const = 0; // Making AForm an abstract class
        
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
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif