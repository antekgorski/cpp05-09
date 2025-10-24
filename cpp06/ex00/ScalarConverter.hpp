/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 13:22:38 by agorski           #+#    #+#             */
/*   Updated: 2025/10/15 20:25:58 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string> // For std::string
#include <iostream> // For std::cout, std::endl
#include <cstdlib>   // For strtod
#include <limits>    // For numeric_limits
#include <cmath>     // For isnan, isinf
#include <iomanip>   // For setprecision, fixed
#include <cctype>    // For isdigit, isprint

class ScalarConverter {
 private:
  ScalarConverter();                               // Prywatny konstruktor
  ScalarConverter(const ScalarConverter& other);   // Prywatny konstruktor kopiujący
  ~ScalarConverter();                              // Prywatny destruktor
  ScalarConverter& operator=(const ScalarConverter& other); // Prywatny operator przypisania
 
 public:
  static void convert(const std::string& literal);
};

#endif // SCALARCONVERTER_HPP