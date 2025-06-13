#include <iostream>

using namespace std;

void CallByValue(int x)
{
	cout << "X address in memory: " << &x << endl;
	x++;
}

void CallByReference(int& x)
{
	cout << "\nX address in memory: " << &x << endl;
	x++;
}

int main() {

	int a = 10;

	cout << "a's value: " << a << endl;
	cout << "a's memory address: " << &a << endl;

	CallByValue(a);
	cout << "a's value after calling CallByValue(a): " << a << endl;

	cout << "----------------" << endl;
	CallByReference(a);
	cout << "a's value after calling CallByReference(a): " << a << endl;

	return 0;
}