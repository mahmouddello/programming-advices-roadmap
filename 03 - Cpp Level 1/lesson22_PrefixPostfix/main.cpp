#include <iostream>
using namespace std;

int main()
{
	short a = 10, b;

	b = a++; // b = 10, then a = a + 1 -> a = 11

	cout << "B = " << b << endl;
	cout << "A = " << a << endl;
	cout << "\n";

	b = ++a; // a = 11, ++a: as is incremented then assigned to b, a -> 12

	cout << "B = " << b << endl;
	cout << "A = " << a << endl;

	return 0;
}