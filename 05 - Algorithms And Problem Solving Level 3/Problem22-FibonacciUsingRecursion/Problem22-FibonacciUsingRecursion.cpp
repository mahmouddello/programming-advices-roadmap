#include <iostream>
#include "../mylibs/headers/input_utils.h"

using namespace std;

void FibonacciProgrammingAdvices(int number, int prev1, int prev2)
{
	int fibNum = 0;

	if (number > 0)
	{
		fibNum = prev1 + prev2;
		prev2 = prev1;
		prev1 = fibNum;

		cout << fibNum << "    ";

		FibonacciProgrammingAdvices(number - 1, prev1, prev2);
	}
}

int FibonacciUsingRecusion(int number)
{
	if (number == 0) return 0; // Correct base case for F(0)
	if (number == 1) return 1; // Correct base case for F(1)

	return FibonacciUsingRecusion(number - 1) + FibonacciUsingRecusion(number - 2);
}

int main() {

	int num = InputsLib::readPositiveNumber("Enter fibonacci: ");

	cout << FibonacciUsingRecusion(num) << endl; // return result only

	FibonacciProgrammingAdvices(num, 0, 1);

	return 0;
}