/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 10:43:16 by agorski           #+#    #+#             */
/*   Updated: 2025/10/22 15:43:00 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::processingLine(std::string &line)
{
    if (line.empty() || line == "date | value")
        return;
    
    size_t pos = line.find("|");
    if (pos == std::string::npos)
        throw std::runtime_error("Invalid line format");
    std::string date = line.substr(0, pos - 1);
    std::string strValue = line.substr(pos + 3);
    std::istringstream iss(strValue);
    float value;
    if (!(iss >> value) || !iss.eof())
        throw std::runtime_error("Invalid value format");
    
    
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

    // Implementation of data loading

}