#include <iostream>

int main() {
    int A = 10, B = 20;

    A += B; // A = A + B
    std::cout << "A = " << A << std::endl;

    A -= B; // A = A - B
    std::cout << "A = " << A << std::endl;

    A *= B; // A = A * B
    std::cout << "A = " << A << std::endl;

    A /= B; // A = A / B
    std::cout << "A = " << A << std::endl;

    A %= B; // A = A % B
    std::cout << "A = " << A << std::endl;

    return 0;
}
