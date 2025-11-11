/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:54:06 by agorski           #+#    #+#             */
/*   Updated: 2025/11/11 17:52:09 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PmergeMe_HPP
#define PmergeMe_HPP

#include <iostream>
#include <cerrno>
#include <cstdlib>
#include <climits>
#include <stdexcept>

template <typename container>
class PmergeMe
{
    private:
        container _data;
        container _sortedData;
        static const int* _JacobsonArray[13];

        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        
        public:
        
        PmergeMe(char **argv);
        ~PmergeMe();
        container FordJohnsonSort(const container& input);
        void parseInput(char **argv);
        void printData(const container& data) const;
        container getData() const;
        container getSortedData() const;
        typename container::size_type getSize() const;
};

template <typename container>
PmergeMe<container>::PmergeMe(char **argv)
{
    parseInput(argv);
};

template <typename container>
PmergeMe<container>::~PmergeMe()
{
};

template <typename container>
typename container::size_type PmergeMe<container>::getSize() const
{
    return _data.size();
};

template <typename container>
container PmergeMe<container>::getData() const
{
    return _data;
};

template <typename container>
container PmergeMe<container>::getSortedData() const
{
    return _sortedData;
};

template <typename container>
void PmergeMe<container>::printData(const container& data) const
{
for (typename container::const_iterator it = data.begin(); it != data.end(); ++it)
    std::cout << *it << " ";
};

template <typename container>
container PmergeMe<container>::FordJohnsonSort(const container& input)
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

//i must implement smtfing like this:
// template <typename Container>
// void insertSmallWithJacobson(Container &large, Container &small, const int* JacobsonArray, size_t jacobSize)
// {
//     std::vector<bool> inserted(small.size(), false); // śledzimy które elementy już wstawiliśmy

//     // 1️⃣ wstaw elementy według Jacobsthala
//     for (size_t i = 0; i < jacobSize; ++i)
//     {
//         size_t idx = JacobsonArray[i];
//         if (idx >= small.size()) break; // nie wychodzimy poza small
//         if (inserted[idx]) continue;   // jeśli już wstawiony, pomijamy

//         typename Container::iterator pos = std::lower_bound(large.begin(), large.end(), small[idx]);
//         large.insert(pos, small[idx]);
//         inserted[idx] = true;
//     }

//     // 2️⃣ wstaw pozostałe elementy
//     for (size_t i = 0; i < small.size(); ++i)
//     {
//         if (!inserted[i])
//         {
//             typename Container::iterator pos = std::lower_bound(large.begin(), large.end(), small[i]);
//             large.insert(pos, small[i]);
//         }
//     }

//     // opcjonalnie: wyczyść small, bo wszystkie elementy zostały wstawione
//     small.clear();
// }


return mainChain;
};

template <typename container>
void PmergeMe<container>::parseInput(char **argv)
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
            throw std::runtime_error("Error");

        // 2. Są śmieci po liczbie → np. "12abc"
        if (*endptr != '\0')
            throw std::runtime_error("Error");

        // 3. Overflow/underflow
        if (errno == ERANGE || val > INT_MAX || val < 0)
            throw std::runtime_error("Error");

        int v = static_cast<int>(val);

        _data.push_back(v);
    }
}
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        exit(1);
    }
};

#endif
