#include <iostream>

using namespace std;


void MyFunction()
{
	static int number = 1;

	cout << number << endl;

	number++;
}

int main() {

	MyFunction();
	MyFunction();
	MyFunction();

	return 0;
}