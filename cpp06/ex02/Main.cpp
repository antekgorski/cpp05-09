/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:23:51 by agorski           #+#    #+#             */
/*   Updated: 2025/10/16 11:42:23 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <typeinfo>  // For std::bad_cast
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void) {
    int choice = std::rand() % 3;
    
    switch (choice) {
        case 0: return new A();
        case 1: return new B();
        default: return new C();
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (...) {}
    
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (...) {}
    
    std::cout << "C" << std::endl;
}

int main() {
    std::srand(std::time(0));
    
    std::cout << "=== DYNAMIC_CAST DEMO ===\n" << std::endl;
    
    // Tworzymy obiekty wszystkich typów
    Base* a = new A();
    Base* b = new B();
    Base* c = new C();
    
    // TEST 1: Pointer cast - SUCCESS
    std::cout << "1. Pointer cast (Base* -> A*): ";
    if (dynamic_cast<A*>(a))
        std::cout << "✅ SUCCESS" << std::endl;
    else
        std::cout << "❌ NULL" << std::endl;
    
    // TEST 2: Pointer cast - FAILURE
    std::cout << "2. Pointer cast wrong type (A* -> B*): ";
    if (dynamic_cast<B*>(a))
        std::cout << "✅ SUCCESS" << std::endl;
    else
        std::cout << "❌ NULL (expected!)" << std::endl;
    
    // TEST 3: Reference cast - SUCCESS
    std::cout << "3. Reference cast (Base& -> B&): ";
    try {
        (void)dynamic_cast<B&>(*b);
        std::cout << "✅ SUCCESS" << std::endl;
    } catch (std::bad_cast&) {
        std::cout << "❌ Exception" << std::endl;
    }
    
    // TEST 4: Reference cast - FAILURE
    std::cout << "4. Reference cast wrong type (C& -> A&): ";
    try {
        (void)dynamic_cast<A&>(*c);
        std::cout << "✅ SUCCESS" << std::endl;
    } catch (std::bad_cast&) {
        std::cout << "❌ Exception (expected!)" << std::endl;
    }
    
    std::cout << "\n=== RANDOM IDENTIFICATION ===\n" << std::endl;
    
    for (int i = 1; i <= 5; i++) {
        Base* obj = generate();
        std::cout << i << ". ptr: ";
        identify(obj);
        std::cout << "   ref: ";
        identify(*obj);
        delete obj;
    }
    
    delete a;
    delete b;
    delete c;
    
    return 0;
}