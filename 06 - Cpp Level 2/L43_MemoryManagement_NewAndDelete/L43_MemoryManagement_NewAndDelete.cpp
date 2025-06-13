#include <iostream>

using namespace std;

int main() {

	// declare an int pointer
	int* ptrX;

	// declate a float pointer
	float* ptrY;

	// dynamic memory allocation, new can be used to allocate memory during runtime
	ptrX = new int;
	ptrY = new float;

	cout << new int << endl;  // returns an adress 

	cout << ptrX << endl;
	cout << ptrY << endl;

	*ptrX = 50;
	*ptrY = 72.4f;

	cout << *ptrX << endl;
	cout << *ptrY << endl;

	// deallocate memory
	delete ptrX;
	delete ptrY;

	return 0;
}