// Copyright 2025 Antoni Gorski
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 10:44:01 by agorski           #+#    #+#             */
/*   Updated: 2025/07/07 17:52:34 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP05_EX02_BUREAUCRAT_HPP_
#define CPP05_EX02_BUREAUCRAT_HPP_

# include <iostream>
# include <string>

// Forward declaration of Form class tolks compilator that Form
// is a class that will be defined later.
class AForm;

class Bureaucrat {
 private:
    const std::string Name_;
    int Grade_;
// block becouse i have const...
    Bureaucrat& operator=(const Bureaucrat& other);

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
    class GradeTooHighException : public std::exception {
     public:
        virtual const char* what() const throw();
    };
class GradeTooLowException : public std::exception {
 public:
    virtual const char* what() const throw();
};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif  // CPP05_EX02_BUREAUCRAT_HPP_
