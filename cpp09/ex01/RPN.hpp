/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 14:06:43 by agorski           #+#    #+#             */
/*   Updated: 2025/10/25 13:10:26 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>

class RPN
{
private:
    std::string _RPN;
    std::stack<int> _stack;
    char _operator;
    int _operand1;
    int _operand2;
    int _result;

    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    
    void _calculate();
    
public:
    RPN(std::string RPN);
    ~RPN();
};

#endif