/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 12:10:27 by agorski           #+#    #+#             */
/*   Updated: 2025/10/20 12:28:30 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept> // for std::out_of_range
#include <cstdlib> // for std::rand, std::srand
#include <ctime> // for std::time

template <typename T>
class Array {
private:
    T* _arr;
    unsigned int _size;

public:
    // Konstruktor domyślny - pusta tablica
    Array() : _arr(NULL), _size(0) {}
    
    // Konstruktor z rozmiarem
    Array(unsigned int n) : _arr(NULL), _size(n) {
        if (n > 0) {
            _arr = new T[n];
            for (unsigned int i = 0; i < n; i++) {
                _arr[i] = T();
            }
        }
    }
    
    // Konstruktor kopiujący
    Array(const Array& other) : _arr(NULL), _size(0) {
        *this = other;
    }
    
    // Destruktor
    ~Array() {
        delete[] _arr;
    }
    
    // Operator przypisania
    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] _arr;
            _size = other._size;
            if (_size > 0) {
                _arr = new T[_size];
                for (unsigned int i = 0; i < _size; i++) {
                    _arr[i] = other._arr[i];
                }
            } else {
                _arr = NULL;
            }
        }
        return *this;
    }
    
    // Operator [] - non-const
    T& operator[](unsigned int index) {
        if (index >= _size)
            throw std::out_of_range("Index out of bounds");
        return _arr[index];
    }
    
    // Operator [] - const
    const T& operator[](unsigned int index) const {
        if (index >= _size)
            throw std::out_of_range("Index out of bounds");
        return _arr[index];
    }
    
    // size()
    unsigned int size() const {
        return _size;
    }
};

#endif