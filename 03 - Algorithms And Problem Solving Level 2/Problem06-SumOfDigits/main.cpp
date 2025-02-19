#include <iostream>

using namespace std;

int ReadPositiveNumber(string message)
{
	int number = 0;

	do {
		cout << message;
		cin >> number;

	} while (number <= 0);

	return number;
}

int SumDigits(int number)
{

	/*
	Assume number is 1234

	1st iteration:
		reminder = number % 10 = 1234 % 10 = 4
		number = number / 10 = 1234 / 10 = 123
		sum = 4

	2nd iteration:
		reminder = number % 10 = 123 % 10 = 3
		number = number / 10 = 123 / 10 = 12
		sum = 4 + 3 = 7

	3rd iteration:
		reminder = number % 10 = 12 % 10 = 2
		number = number / 10 = 12 / 10 = 1
		sum = 4 + 3 + 2 = 9

	4th iteration:
		reminder = number % 10 = 1 % 10 = 1
		number = number / 10 = 1 / 10 = 0
		sum = 4 + 3 + 2 + 1 = 10
*/

	int reminder = 0, sum = 0;

	while (number > 0)
	{
		reminder = number % 10;
		sum += reminder;
		number = number / 10;
	}

	return sum;
}

void PrintResult(int sum)
{
	cout << "Sum of the digits is = " << sum << endl;
}

int main()
{
	PrintResult(SumDigits(ReadPositiveNumber("Please enter a positive number: ")));
}
