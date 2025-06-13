#include <iostream>

int add(int, int);

int main() {
    std::cout << add(5, 3); // Error: 'add' was not declared in this scope
    return 0;
}

int add(int a, int b) { // Function definition after main()
    return a + b;
}
