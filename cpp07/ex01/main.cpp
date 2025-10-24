/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:59:22 by agorski           #+#    #+#             */
/*   Updated: 2025/10/17 14:13:33 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> // for std::cout, std::endl
#include "iter.hpp" // for iter function

template <typename T>
void print(const T& x) {
    std::cout << x << " ";
}

template <typename T>
void increment(T& x) {
    x++;
}

int main() {
    // Test 1: Non-const array
    std::cout << "Non-const array:" << std::endl;
    int arr[] = {1, 2, 3, 4, 5};
    
    std::cout << "Before: ";
    iter(arr, 5, print<int>);
    std::cout << std::endl;
    
    iter(arr, 5, increment<int>);
    
    std::cout << "After:  ";
    iter(arr, 5, print<int>);
    std::cout << std::endl << std::endl;
    
    // Test 2: Const array
    std::cout << "Const array:" << std::endl;
    const int constArr[] = {10, 20, 30};
    
    iter(constArr, 3, print<int>);
    std::cout << std::endl;
    
     //iter(constArr, 3, increment<int>); // Uncomment - compilation error!
    
    return 0;
}