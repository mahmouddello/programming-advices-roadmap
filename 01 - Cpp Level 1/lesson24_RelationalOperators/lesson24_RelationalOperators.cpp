#include <iostream>
using namespace std;

void Homework()
{
    // Take A and B inputs, and do the comparision we discussed in the video.
    int a, b;

    cout << "Enter a's value: ";
    cin >> a;

    cout << "Enter b's value: ";
    cin >> b;

    cout << a << " == " << b << " is " << (a == b) << endl;
    cout << a << " != " << b << " is " << (a != b) << endl;

    cout << a << " > " << b << " is " << (a > b) << endl;
    cout << a << " < " << b << " is " << (a < b) << endl;

    cout << a << " >= " << b << " is " << (a >= b) << endl;
    cout << a << " <= " << b << " is " << (a <= b) << endl;

}

int main() {
    //int A = 20, B = 20;

    //cout << (A == B) << endl; // true (1)
    //cout << (A != B) << endl; // false (0)

    //cout << (A > B) << endl; // false (0)
    //cout << (A < B) << endl; // false (0)

    //cout << (A >= B) << endl; // true (1)
    //cout << (A <= B) << endl; // true (1)

    Homework();

    return 0;
}