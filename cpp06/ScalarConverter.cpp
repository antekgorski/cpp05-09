/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 13:22:29 by agorski           #+#    #+#             */
/*   Updated: 2025/07/14 17:33:17 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

ScalarConverter::ScalarConverter() : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    std::cout << "Assignment operator called" << std::endl;
    if (this != &other)
        _value = other._value;
    return *this;
}

ScalarConverter::~ScalarConverter() {
    std::cout << "Destructor called" << std::endl;
}

void ScalarConverter::convert(std::string value) {
    double temp;
    
//tead obout static cast and see code :
//https://github.com/cheroualiyakoub/42-CPP06/blob/main/ex00/src/ScalarConverter.cpp

    this->char_ = 0;
    this->int_ = 0;
    this->float_ = 0;
    this->double_ = 0;
}