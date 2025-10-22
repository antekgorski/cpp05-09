/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 10:43:14 by agorski           #+#    #+#             */
/*   Updated: 2025/10/22 18:26:46 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

class BitcoinExchange
{
private:
    std::map<std::string, float> _data;

    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    void processingLine(std::string &line);
    void inputFormatIsValid(const std::string &strValue, const std::string &date);
    
public:
    BitcoinExchange();
    ~BitcoinExchange();
    void loadData(const std::string &filename);
    void loadInput(const int argc, const std::string &filename);
    
private:
};

#endif