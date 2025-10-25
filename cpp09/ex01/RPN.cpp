/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 14:06:48 by agorski           #+#    #+#             */
/*   Updated: 2025/10/25 13:29:26 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(std::string RPN) : _RPN(RPN)
{
    _calculate();
}

RPN::~RPN()
{
}

void RPN::_calculate()
{
    while (!_RPN.empty())
    {
        if (_RPN[0] == ' ')
        {
            _RPN.erase(0, 1);
            continue;
        }
        char c = _RPN[0];
        _RPN.erase(0, 1);
        if (c >= '0' && c <= '9')
        {
            _stack.push(c - '0');
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            if (_stack.size() < 2)
            {
                std::cerr << "Error: Not enough operands in the stack." << std::endl;
                return;
            }
            _operand2 = _stack.top();
            _stack.pop();
            _operand1 = _stack.top();
            _stack.pop();
            switch (c)
            {
                case '+':
                    _result = _operand1 + _operand2;
                    break;
                case '-':
                    _result = _operand1 - _operand2;
                    break;
                case '*':
                    _result = _operand1 * _operand2;
                    break;
                case '/':
                    if (_operand2 == 0)
                    {
                        std::cerr << "Error: Division by zero." << std::endl;
                        return;
                    }
                    _result = _operand1 / _operand2;
                    break;
            }
            _stack.push(_result);
        }
        else
            throw std::invalid_argument("Error: Invalid character in RPN expression.");
    }
    if (_stack.size() != 1)
        throw std::runtime_error("Error: The RPN expression is invalid.");
    std::cout << _stack.top() << std::endl;
}
