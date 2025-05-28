/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 10:44:01 by agorski           #+#    #+#             */
/*   Updated: 2025/05/28 16:56:50 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class AForm; // Forward declaration of Form class tolks compilator that Form is a class that will be defined later.

class Bureaucrat
{
    private:
        const std::string Name_;
        int Grade_;
        Bureaucrat& operator=(const Bureaucrat& other);//block becouse i have const...
    public:
        Bureaucrat();
        Bureaucrat(std::string Name, int Grade);
        Bureaucrat(const Bureaucrat& other);
        ~Bureaucrat();
        
        std::string getName() const;
        int getGrade() const;
        void Increment();
        void Decrement();
        void signForm(AForm& form);

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

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif