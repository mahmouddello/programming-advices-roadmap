#include <iostream>

using namespace std;

int main() {

    /*
        A void pointer (generic pointer) can store addresses of different data types
        but must be type-cast before dereferencing.
    */

    void* ptr;  // Generic pointer
    float a = 10.5;



    ptr = &a;  // Storing the address of a float variable

    cout << "Address stored in ptr: " << ptr << endl;
    cout << "Value of a (via ptr): " << *(static_cast<float*>(ptr)) << endl;

    int b = 20;
    ptr = &b;  // Now ptr points to an int variable

    cout << "Address stored in ptr: " << ptr << endl;
    cout << "Value of b (via ptr): " << *(static_cast<int*>(ptr)) << endl;

    cout << "\n----------TESTS----------\n";

    char h = 'h';
    int A = 65;

    void* ptrChar = &h;

    cout << "ptrChar address = " << ptrChar << endl;
    cout << "ptrChar value: " << *(static_cast<char*>(ptrChar)) << endl;

    ptrChar = &A;

    cout << "ptrChar address = " << ptrChar << endl;
    cout << "ptrChar value: " << *(static_cast<char*>(ptrChar)) << endl;

    return 0;
}
