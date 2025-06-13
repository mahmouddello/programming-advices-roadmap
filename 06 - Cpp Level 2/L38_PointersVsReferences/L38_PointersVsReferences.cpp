#include <iostream>

using namespace std;

int main() {

	int a = 10;
	int& x = a; // x is alias for a (reference)

	cout << &a << endl;
	cout << &x << endl;

	int* p = &a;

	cout << p << endl;
	cout << *p << endl;

	// we can't change the reference of x during runtime
	// &x = b; is not valid
	int b = 20;

	p = &b;

	cout << p << endl;
	cout << *p << endl;

	return 0;
}