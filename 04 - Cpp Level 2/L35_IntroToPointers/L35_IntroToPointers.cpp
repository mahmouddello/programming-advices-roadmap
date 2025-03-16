#include <iostream>

using namespace std;

int main() {

	int a = 10;
	int b = 20;

	cout << "a's value = " << a << endl;
	cout << "a's address = " << &a << endl;

	// pointer that stores the address of variable `a` in memory.
	// we can't store values in pointers, just address
	int* p = &a;

	cout << "pointer's value = " << p << endl;

	p = &b; // changing the pointer from pointing on a, to the variable b.

	cout << "pointer's value = " << p << endl;

	return 0;
}