/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 10:28:22 by agorski           #+#    #+#             */
/*   Updated: 2025/10/21 11:27:59 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "span.hpp"
#include <iostream>

Span::Span() : _N(0) {}

Span::Span(unsigned int N) : _N(N) {}

Span::Span(const Span &other) : _N(other._N), _span(other._span) {}

Span::~Span() {}

Span &Span::operator=(const Span &other) {
    if (this != &other) {
        _N = other._N;
        _span = other._span;
    }
    return *this;
}

void Span::addNumber(int number) {
    if (_span.size() >= _N) {
        throw std::out_of_range("too many numbers added, span is full");
    }
    _span.push_back(number);
}

int Span::shortestSpan() const {
    if (_span.size() < 2) {
        throw std::logic_error("not enough numbers to find a span");
    }
    std::vector<int> sortedSpan = _span;
    std::sort(sortedSpan.begin(), sortedSpan.end());
    int minSpan = sortedSpan[1] - sortedSpan[0];

    for (size_t i = 2; i < sortedSpan.size(); i++) {
        int diff = sortedSpan[i] - sortedSpan[i - 1];
        if (diff < minSpan)
            minSpan = diff;
    }
    return minSpan;
}

int Span::longestSpan() const {
    if (_span.size() < 2) {
        throw std::logic_error("not enough numbers to find a span");
    }
    return *std::max_element(_span.begin(), _span.end()) - *std::min_element(_span.begin(), _span.end());
}

void Span::rangeOfNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    for (std::vector<int>::iterator it = begin; it != end; ++it) {
        try {
        addNumber(*it);
        } catch (const std::exception &e) {
            std::cerr << "Error adding number: " << e.what() << std::endl;
            break;
        }
}
}
