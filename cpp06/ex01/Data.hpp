#ifndef DATA_HPP
#define DATA_HPP

#include <string>
#include <iostream>

struct Data {
    int value;
    std::string name;
    float ratio;

    Data(int val = 0, const std::string& n = "", float r = 0.0f);
    void display() const;
};

#endif