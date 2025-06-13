#include <iostream>

using namespace std;

int x = 10;  // Global variable

void myFunction() {
    int x = 20;  // Local variable
    cout << "Local x inside function: " << x << std::endl;  // Output: 20
    cout << "Global x inside function: " << ::x << std::endl;  // Output: 10
}

int main() {

    int x = 30;

    cout << "Local x inside main function: " << x << std::endl;  // Output: 30
    myFunction();

    cout << "Global x outside function after calling myFunction: " << ::x << std::endl;  // Output: 10

    return 0;
}
