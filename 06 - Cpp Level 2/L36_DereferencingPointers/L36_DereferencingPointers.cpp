#include <iostream>

using namespace std;

int main() {

    int a = 10;
    int* p = &a;

    cout << "a's value = " << a << endl;
    cout << "a's address = " << &a << endl;

    // Prints the memory address stored in the pointer (address of 'a')
    cout << "Pointer's value = " << p << endl;
    // Prints the value stored at the referenced address (value of 'a')
    cout << "Value of the address tha pointer is pointiong to = " << *p << endl;

    *p = 20; // change also applied to a

    cout << a << endl;
    cout << *p << endl;

    a = 30;

    cout << a << endl;
    cout << *p << endl;

    return 0;
}
