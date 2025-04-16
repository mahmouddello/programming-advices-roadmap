#include <iostream>
#include <iomanip>
#include "D:/MyCPP_Libs/InputsLib.h"

using namespace std;

void FibonacciUsingLoop(int number)
{
	int prev1 = 0, prev2 = 1;
	int nextFib = 0;

	cout << "1    ";

	for (int i = 1; i < number; i++)
	{
		nextFib = prev1 + prev2;
		prev1 = prev2;
		prev2 = nextFib;

		cout << nextFib << "    ";
	}
}

int main()
{
	int num = InputsLib::readPositiveNumber("Enter fibonacci number: ");

	FibonacciUsingLoop(num);

	return 0;
}