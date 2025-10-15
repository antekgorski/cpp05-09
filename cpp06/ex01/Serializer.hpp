#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h> // For uintptr_t
#include "Data.hpp" // For Data*

// Static-only class - nie można tworzyć instancji
class Serializer {
private:
    Serializer();
    Serializer(const Serializer& other);
    ~Serializer();
    Serializer& operator=(const Serializer& other);

public:
    // Konwertuje wskaźnik Data* na uintptr_t
    static uintptr_t serialize(Data* ptr);
    // Konwertuje uintptr_t z powrotem na Data*
    static Data* deserialize(uintptr_t raw);
};

#endif