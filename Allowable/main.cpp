// CRTP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "protected_class.h"
#include "allow.h"

int main()
{
    protected_class prot1(10, 20.3);
    protected_class prot2(20, 30.4);

    std::cout << prot1 << std::endl;
    std::cout << prot2 << std::endl;

    // If we try to change protected objects outside allowable class methods, it does not compile
    //prot1.set_int(5);
    //prot1.set_double(6);

    allow all;
    all.change(prot2, 10, 11.11);
    std::cout << "==================================" << std::endl;
    std::cout << prot1 << std::endl;
    std::cout << prot2 << std::endl;
}
