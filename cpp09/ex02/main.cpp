/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:54:09 by agorski           #+#    #+#             */
/*   Updated: 2025/11/15 20:06:30 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <vector>
#include <deque>
#include <ctime>
#include <iomanip>

int main(int argc, char **argv)
{
    if (argc < 2 || argc > 3000)
    {
        std::cerr << "Error: bad number's of arguments" << std::endl;
        return 1;
    }
    
     
    clock_t vStart, vEnd;
    vStart = clock();
    PmergeMe< std::vector<int> > vectorSorter(argv);
    std::vector<int> sortedVector = vectorSorter.FordJohnsonSort(vectorSorter.getData());
    vEnd = clock();
    double vDuration = static_cast<double>(vEnd - vStart) / CLOCKS_PER_SEC * 1000000; // microseconds
    
    clock_t dStart, dEnd;
    dStart = clock();
    PmergeMe< std::deque<int> > dequeSorter(argv);
    std::deque<int> sortedDeque = dequeSorter.FordJohnsonSort(dequeSorter.getData());
    dEnd = clock();
    double dDuration = static_cast<double>(dEnd - dStart) / CLOCKS_PER_SEC * 1000000;
    
    std::cout << "Before:" << '\t';
    // vectorSorter.printData(vectorSorter.getData());
    dequeSorter.printData(dequeSorter.getData());
    std::cout << std::endl;
    std::cout <<  << "After:" << '\t';
    vectorSorter.printData(sortedVector);
    // dequeSorter.printData(sortedDeque);

    std::cout << std::endl;
    std::cout << "Time to process a range of " 
                << vectorSorter.getData().size() 
                << " elements with std::vector:" << "\t"
                << std::fixed << std::setprecision(5) 
                << vDuration << " us" << std::endl;

    std::cout << "Time to process a range of " 
            << vectorSorter.getData().size() 
                << " elements with std::deque:" << "\t"
                << std::fixed << std::setprecision(5) 
                << dDuration << " us" << std::endl;

    return 0;
}   