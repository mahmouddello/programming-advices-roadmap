#include <iostream>

/*
    register was deprecated in C++11 and removed in C++17.
    It was just a hint for optimization, and compilers don’t need it anymore.
    Registers are fast, but register wasn’t dangerous—just obsolete.
*/

int main()
{
    std::cout << "Hello World!\n";
}
