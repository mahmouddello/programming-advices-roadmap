#include <iostream>

using namespace std;

int main() {

	int array[4] = {10, 20, 30, 40};
	int* ptr = array; // ptr points to the address of first variable in the array

	// ptr is equivalent to &arr[0]
	// ptr + 1 is equivalent to &arr[1]
	// ptr + 2 is equivalent to &arr[2]
	// ptr + 3 is equivalent to &arr[3]

	// address of the variables
	cout << ptr << endl;
	cout << ptr + 1 << endl;
	cout << ptr + 2 << endl;
	cout << ptr + 3 << endl;

	// value unpacking - *(ptr) = arr[0]
	cout << *(ptr) << endl;
	cout << *(ptr + 1) << endl;
	cout << *(ptr + 2) << endl;
	cout << *(ptr + 3) << endl;

	cout << "-------------" << endl;

	// another way to access the values
	for (int i = 0; i <= 3; i++)
	{
		cout << *(ptr + i) << endl;
	}

	return 0;
}