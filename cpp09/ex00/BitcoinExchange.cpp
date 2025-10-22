/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 10:43:16 by agorski           #+#    #+#             */
/*   Updated: 2025/10/22 12:53:05 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::inputProcessing(const int argc, const std::string &filename)
{
    if (argc !=2)
        throw std::runtime_error("Usage ./btc <input_file>");
    std::ifstream    file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("File open imput error");
    // Implementation of input processing
}
void BitcoinExchange::loadData(const std::string &filename)
{
    std::ifstream    file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("File open data error");

    // Implementation of data loading

}