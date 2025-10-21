#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>

class Span {
    public:
        Span();
        Span(unsigned int N);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();

        void addNumber(int number);
        int shortestSpan() const;
        int longestSpan() const;
        void rangeOfNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);

    private:
        unsigned int _N;
        std::vector<int> _span;
};

#endif