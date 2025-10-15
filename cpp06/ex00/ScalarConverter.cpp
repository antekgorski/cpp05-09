/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 13:22:29 by agorski           #+#    #+#             */
/*   Updated: 2025/10/15 20:25:39 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}

static void PrintAllImpossible() {
    std::cout << "char: impossible\n"
              << "int: impossible\n"
              << "float: impossible\n"
              << "double: impossible\n";
}

void ScalarConverter::convert(const std::string& literal) {

    if (literal.empty()) {
        PrintAllImpossible();
        return;
    }
    
    char* end;
    double d = std::strtod(literal.c_str(), &end);
    
    // Sprawdź czy to pojedynczy znak (nie cyfra)
    if (literal.length() == 1 && !std::isdigit(literal[0])) {
        d = static_cast<double>(literal[0]);
    }
    // Sprawdź czy cały string został sparsowany (poza opcjonalnym 'f')
    else if (*end != '\0' && !(end[0] == 'f' && end[1] == '\0')) {
        PrintAllImpossible();
        return;
    }
    
    // Konwersja na char
    std::cout << "char: ";
    if (std::isnan(d) || std::isinf(d) ||
        d < std::numeric_limits<char>::min() ||
        d > std::numeric_limits<char>::max()) {
        std::cout << "impossible" << std::endl;
    } 
    else if (!std::isprint(static_cast<char>(d))) {
        std::cout << "Non displayable" << std::endl;
    } 
    else {
        std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
    }
    
    // Konwersja na int
    std::cout << "int: ";
    if (std::isnan(d) || std::isinf(d) ||
        d < std::numeric_limits<int>::min() ||
        d > std::numeric_limits<int>::max()) {
        std::cout << "impossible" << std::endl;
    } 
    else {
        std::cout << static_cast<int>(d) << std::endl;
    }
    
    // Konwersja na float i double
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}