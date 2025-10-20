#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main() {
    Data data;
    data.value = 42;
    data.name = "Hello";
    data.ratio = 3.14f;

    std::cout << "Original: " << &data << std::endl;
    std::cout << data.value << ", " << data.name << ", " << data.ratio << std::endl;

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "\nSerialized: " << raw << std::endl;
    Data* ptr = Serializer::deserialize(raw);

    std::cout << "\nDeserialized: " << ptr << std::endl;
    std::cout << ptr->value << ", " << ptr->name << ", " << ptr->ratio << std::endl;
    std::cout << "\nMatch: " << (ptr == &data ? "YES" : "NO") << std::endl;

    return 0;
}