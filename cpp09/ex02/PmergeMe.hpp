/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:54:06 by agorski           #+#    #+#             */
/*   Updated: 2025/11/05 14:25:54 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PmergeMe_HPP
#define PmergeMe_HPP

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <cerrno>
#include <cstdlib>
#include <climits>
#include <stdexcept>
class PmergeMe
{
    private:
    
        std::deque<int> _deque;
        std::vector<int> _vector;

        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();
        
    public:

        template <typename container>
        container FordJohnsonSort(container& input);

        PmergeMe(char **argv);
        void parseInput(char **argv);
        
};

#endif
