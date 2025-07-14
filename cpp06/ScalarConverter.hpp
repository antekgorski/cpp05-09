/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 13:22:38 by agorski           #+#    #+#             */
/*   Updated: 2025/07/14 17:25:24 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {
 private:
  char char_;
  int int_;
  float float_;
  double double_;
  std::string _value;
  
  ScalarConverter();
  ScalarConverter(const ScalarConverter& other);
  ~ScalarConverter();
  ScalarConverter& operator=(const ScalarConverter& other);

 public:
   void convert(std::string value);
};

#endif // SCALARCONVERTER_HPP