/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antek <antek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:54:06 by agorski           #+#    #+#             */
/*   Updated: 2025/11/13 01:21:31 by antek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PmergeMe_HPP
#define PmergeMe_HPP

#include <iostream>
#include <cerrno>
#include <cstdlib>
#include <climits>
#include <stdexcept>

#define MAX_SIZE 3000
#define MAX_SMALL 1500

template <typename container>
class PmergeMe
{
    private:
        container _data;
        container _sortedData;

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

small.clear();
large.clear();

typename container::size_type i = 0;
while (i + 1 < input.size())
{
    if (input[i] < input[i + 1])
    {
        small.push_back(input[i]);
        std::cout << "small insert: " << input[i] << std::endl;
        large.push_back(input[i + 1]);
        std::cout << "large insert: " << input[i + 1] << std::endl;
    }
    else
    {
        small.push_back(input[i + 1]);
        std::cout << "large insert: " << input[i] << std::endl;
        large.push_back(input[i]);
        std::cout << "small insert: " << input[i + 1] << std::endl;
    }
    i += 2;
}

// 2. Handle odd element
if (input.size() % 2 != 0)
{
    small.push_back(input.back());
    std::cout << "odd small insert: " << input.back() << std::endl;
}

// 2. Sort "large" elements recursively
large = FordJohnsonSort(large);

int JacobsonArray[12] = { 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731 };

// 3. Insert "small" elements into "large" using Jacobson's sequence

//set range for lower_bound search
for (size_t j = 0; j < 12; ++j)
{
    size_t prev = (j == 0) ? 0 : JacobsonArray[j - 1];
    size_t elementsToInsert = JacobsonArray[j] - prev;
    int sizeOfSmall = small.size();
    if (sizeOfSmall < JacobsonArray[j])
    {
        elementsToInsert = sizeOfSmall - prev;
        JacobsonArray[j] = sizeOfSmall;
    }
    for (size_t k = elementsToInsert; k > 0; --k)
    {          
        std::cout << "large order: ";
        
        for (typename container::iterator it = large.begin(); it != large.end(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;

// dinamic array of iterators to elements in "large"
        typename container::iterator rangeEnd = large.begin();
        std::advance(rangeEnd, prev + k);
        
        typename container::iterator pos =
        std::lower_bound(large.begin(), rangeEnd, small[prev + k - 1]);
        large.insert(pos, small[prev + k - 1]);
        std::cout << std::endl;
    }
}

mainChain = large;
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
