// CRTP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "protected_class.h"
#include "Allow.h"


class A
{

};

class B: private A
{};


class C: private B
{};


class D : private C
{};

int main()
{
    static_assert(std::is_base_of_v<A, B>, "Not base");
    static_assert(std::is_base_of_v<A, C>, "Not base");
    static_assert(std::is_base_of_v<A, D>, "Not base");

    protected_class prot1(10, 20.3);
    protected_class prot2(20, 30.4);

    std::cout << prot1 << std::endl;
    std::cout << prot2 << std::endl;

    std::cout << "--------------------------------------" << std::endl;
//    prot1.set_int(5);
//    prot1.set_int<current_type>(5);
//    prot1.set_double(6);
    //prot1.set_double_en(10);
//    prot1.set_double_en<det_allow>(10);

//    prot1.set_double_boost<allow::all>(11.11);

    allow all;
    all.method(prot2, 10, 11.11);
    std::cout << "==================================" << std::endl;
    std::cout << prot1 << std::endl;
    std::cout << prot2 << std::endl;

    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
