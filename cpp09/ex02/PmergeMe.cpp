/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:54:03 by agorski           #+#    #+#             */
/*   Updated: 2025/11/05 14:26:30 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename container>
container FordJohnsonSort(container& input)
{
// 1. Separete into pairs and sort each pair.
if (input.size() <= 1)
        return input;
    
container small, large, mainChain;

typename container::size_type i = 0;
while (i + 1 < input.size())
{
    if (input[i] < input[i + 1])
    {
        small.push_back(input[i]);
        large.push_back(input[i + 1]);
    }
    else
    {
        small.push_back(input[i + 1]);
        large.push_back(input[i]);
    }
    i += 2;
}

// 2. Handle odd element
if (input.size() % 2 != 0)
{
    small.push_back(input.back());
}

// 2. Sort "large" elements recursively
large = FordJohnsonSort(large);

// 3. Merge "small" and "large"
mainChain = large;

}

PmergeMe::PmergeMe(char **argv)
{
    parseInput(argv);
}

void PmergeMe::parseInput(char **argv)
{
    try
{
    for (int i = 1; argv[i]; ++i)
    {
        char *endptr = NULL;
        errno = 0;

        long val = std::strtol(argv[i], &endptr, 10);

        // 1. Nic nie zostało sparsowane → nie jest liczbą
        if (endptr == argv[i])
            throw std::runtime_error("Error: invalid number: " + std::string(argv[i]));

        // 2. Są śmieci po liczbie → np. "12abc"
        if (*endptr != '\0')
            throw std::runtime_error("Error: invalid trailing characters in: " + std::string(argv[i]));

        // 3. Overflow/underflow
        if (errno == ERANGE || val > INT_MAX || val < 0)
            throw std::runtime_error("Error: out-of-range number: " + std::string(argv[i]));

        int v = static_cast<int>(val);

        _vector.push_back(v);
        _deque.push_back(v);
    }
}
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        exit(1);
    }
}
