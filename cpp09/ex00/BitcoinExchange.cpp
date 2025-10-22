/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 10:43:16 by agorski           #+#    #+#             */
/*   Updated: 2025/10/22 16:49:44 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::inputFormatIsValid(const std::string &strValue, const std::string &date)
{
    // value validation
    std::istringstream iss(strValue);
    float value;
    if (!(iss >> value) || !iss.eof())
        throw std::runtime_error("Invalid input value format");
    if (value < 0)
        throw std::runtime_error("Negative input value");
    if (value > 1000)
        throw std::runtime_error("input Value too large");

    // date validation Format: YYYY-MM-DD
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        throw std::runtime_error("input Invalid date format");

    for (size_t i = 0; i < date.length(); ++i)
    {
        if (i == 4 || i == 7)
            continue;
        if (!isdigit(date[i]))
            throw std::runtime_error("input Invalid date format");
    }
    
    int year = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int day = atoi(date.substr(8, 2).c_str());
    
    // date validation range
    if (year < 2009 || year > 2025)
        throw std::runtime_error("input Year out of range");
    if (month < 1 || month > 12)
        throw std::runtime_error("input Month out of range");
    if (day < 1 || day > 31)
        throw std::runtime_error("input Day out of range");
        
    return true;
}

void BitcoinExchange::processingLine(std::string &line)
{
    if (line.empty() || line == "date | value")
        return;
    
    size_t pos = line.find("|");
    if (pos == std::string::npos)
        throw std::runtime_error("Invalid input line format");
    std::string date = line.substr(0, pos - 1);
    std::string strValue = line.substr(pos + 3);

    if (inputFormatIsValid(strValue, date))
        std::cout << date << " => " << strValue << std::endl;
        
}

void BitcoinExchange::loadInput(const int argc, const std::string &filename)
{
    if (argc !=2)
        throw std::runtime_error("Usage ./btc <input_file>");
    std::ifstream    file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("File open imput error");
    
    std::string line;
    while (std::getline(file, line))
    {
        processingLine(line);
    }
    file.close();
}
void BitcoinExchange::loadData(const std::string &filename)
{
    std::ifstream    file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("File open data error");
    while (std::getline(file, line))
    {
        size_t pos = line.find(",");
        if (pos == std::string::npos)
            continue; // skip invalid lines
        std::string date = line.substr(0, pos);
        std::string strValue = line.substr(pos + 1);
        
    }
    file.close();
}