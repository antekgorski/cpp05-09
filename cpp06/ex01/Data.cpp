#include "Data.hpp"

Data::Data(int val, const std::string& n, float r)
    : value(val), name(n), ratio(r) {}

void Data::display() const {
    std::cout << "Data content: value=" << value
              << ", name='" << name << "'"
              << ", ratio=" << ratio << std::endl;
}