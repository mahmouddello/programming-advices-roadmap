#include <iostream>

using namespace std;

void SwapByReference(int& a, int& b)
{
	int temp = 0;
	temp = a;
	a = b;
	b = temp;
}

void SwapByReferenceWithPointer(int* a, int* b)
{
	int temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;
}

int main() {

	int a = 10, b = 20;
	int x = 40, y = 50;

	cout << "Before Swapping (a,b)" << endl;
	cout << "(before) a = " << a << endl;
	cout << "(before) b = " << b << endl;

	SwapByReference(a, b); // we send just values, the function handle swapping becuase of references
	cout << "(After) a = " << a << endl;
	cout << "(After) b = " << b << endl;

	cout << "-------------------" << endl;

	cout << "Before Swapping (x,y)" << endl;
	cout << "(before) x = " << x << endl;
	cout << "(before) y = " << y << endl;

	SwapByReferenceWithPointer(&x, &y); // we send the address becuase function expect a pointer value
	cout << "(After) x = " << x << endl;
	cout << "(After) y = " << y << endl;

	return 0;
}