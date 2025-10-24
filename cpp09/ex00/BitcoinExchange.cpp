/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 10:43:16 by agorski           #+#    #+#             */
/*   Updated: 2025/10/23 16:05:40 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}

float BitcoinExchange::inputFormatIsValid(const std::string &strValue, const std::string &date)
{
    // value validation
    std::istringstream iss(strValue);
    float value;
    
    if (!(iss >> value) || !iss.eof())
        throw std::runtime_error("bad input => " + strValue);
    if (value < 0)
        throw std::runtime_error("Error: not a positive number.");
    if (value > 1000)
        throw std::runtime_error("Error: too large a number.");

    // date validation Format: YYYY-MM-DD
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        throw std::runtime_error("bad input => " + date);

    //check digit
    for (size_t i = 0; i < date.length(); ++i)
    {
        if (i == 4 || i == 7)
            continue;
        if (!isdigit(date[i]))
            throw std::runtime_error("bad input => " + date);
    }
    
    int year, month, day;
    std::istringstream(date.substr(0, 4)) >> year;
    std::istringstream(date.substr(5, 2)) >> month;
    std::istringstream(date.substr(8, 2)) >> day;
    
    // date validation range
    if (year < 2009 || year > 2025)
        throw std::runtime_error("bad input => " + date);
    if (month < 1 || month > 12)
        throw std::runtime_error("bad input => " + date);
    if (day < 1 || day > 31)
        throw std::runtime_error("bad input => " + date);

    return value;
}

void BitcoinExchange::processingLine(std::string &line)
{
    if (line.empty() || line == "date | value")
        return;
    try
    {
    size_t pos = line.find("|");
    if (pos == std::string::npos)
        throw std::runtime_error("Error: bad input => " + line);
        
    std::string date = line.substr(0, pos - 1);
    std::string strValue = line.substr(pos + 2);
    
    float value = inputFormatIsValid(strValue, date);
    
    std::cout << date << " => " << strValue << " = ";
    std::map<std::string, float>::iterator it = _data.lower_bound(date); //Returns an iterator pointing to the first element that is not less than key.
    if (it != _data.begin())
    {
        if (it != _data.end() && it->first == date)
        {
            std::cout << value * it->second << std::endl;
            return;
        }
        --it;
        std::cout << value * it->second << std::endl;
    }
    else
        throw std::runtime_error("this date is too early");
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }    
}

void BitcoinExchange::loadInput(const int argc, const std::string &filename)
{
    if (argc !=2)
        throw std::runtime_error("Usage ./btc <input_file>");
    std::ifstream    file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("File open input error");
    
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
        
    std::string line;
    std::getline(file, line); // skip the first line
    
    while (std::getline(file, line))
    {
        size_t pos = line.find(",");
        if (pos == std::string::npos)
        continue; // skip invalid lines
        std::string date = line.substr(0, pos);
        std::string strValue = line.substr(pos + 1);
        float value;
        std::istringstream iss(strValue);
        if (!(iss >> value) || !iss.eof())
        continue; // skip invalid values
        _data[date] = value;
    }
    file.close();
    if (_data.empty())
        throw std::runtime_error("No data available please load data.csv file");
}