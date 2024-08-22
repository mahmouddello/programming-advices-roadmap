#include <iostream>

using namespace std;

// Call by value: modifying a copy of the variable sent as an argument
// By reference: access the reference (id) of the variable in memory and perform change. indicated with "&" sign.

void SwapNumbers(int& num1, int& num2)
{
	int temp;
	temp = num1;
	num1 = num2;
	num2 = temp;
}

int main()
{

	int num1 = 10, num2 = 20;

	cout << "Before Swap\n" << "Num1: " << num1 << ", Num2: " << num2 << endl;

	SwapNumbers(num1, num2);

	cout << "After Swap\n" << "Num1: " << num1 << ", Num2: " << num2 << endl;

	return 0;
}