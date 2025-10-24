/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 10:43:21 by agorski           #+#    #+#             */
/*   Updated: 2025/10/25 00:41:31 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    // CONSTRUCTOR TEST
    std::cout << "constructor test" << std::endl;
    try
    {
        Bureaucrat test1("test1", 151);
        std::cout << "Constructor value ok: " << test1;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception cath Constructor value out of range: " << e.what() << std::endl;
    }

    // COPY INCREMENT TEST
    std::cout << std::endl
              << "Increment test" << std::endl;
    try
    {
        Bureaucrat test2("test2", 1);
        std::cout << "Before increment: " << test2;
        test2.Increment();
        std::cout << "After increment: " << test2;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception cath Increment value out of range: " << e.what() << std::endl;
    }
    // DECREMENT TEST
    std::cout << std::endl
              << "Decrement test" << std::endl;
    try
    {
        Bureaucrat test3("test3", 149);
        std::cout << "Before decrement: " << test3;
        test3.Decrement();
        std::cout << "After decrement: " << test3;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception cath Decrement value out of range: " << e.what() << std::endl;
    }
}