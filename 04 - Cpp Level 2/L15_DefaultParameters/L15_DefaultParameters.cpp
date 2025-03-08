#include <iostream>

using namespace std;

int MyMultiply(int, int, int = 1, int = 1);

int MySum(int a, int b, int c = 0, int d = 0) {
    return (a + b + c + d);
}

int main() {
    cout << MySum(10, 20) << endl;        // Uses defaults: 10 + 20 + 0 + 0 = 30
    cout << MySum(10, 20, 30) << endl;    // Uses one default: 10 + 20 + 30 + 0 = 60
    cout << MySum(10, 20, 30, 40) << endl;// No defaults used: 10 + 20 + 30 + 40 = 100

    cout << MyMultiply(10, 20) << endl; // Uses defaults: 10 * 20 * 1 * 1 = 200
    cout << MyMultiply(10, 20, 30) << endl; // Uses defaults: 10 * 20 * 30 * 1 = 6000
    cout << MyMultiply(10, 20, 30, 40) << endl; // Uses defaults: 10 * 20 * 30 * 40 = 240000

    return 0;
}

// when we use defition and declration, we type the optional params in defition,
// and we cant re-define them in declaration
int MyMultiply(int a, int b, int c, int d) 
{
    return (a * b * c * d);
}
