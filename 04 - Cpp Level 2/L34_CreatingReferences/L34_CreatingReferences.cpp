#include <iostream>

using namespace std;

int main() {

	int a = 10; 
	int& x = a; // reference to a

	cout << "Address of a: " << &a << endl;
	cout << "Address of x: " << &x << endl;

	cout << "Value of a: " << a << endl;
	cout << "Value of x: " << x << endl;

	return 0;
}							  