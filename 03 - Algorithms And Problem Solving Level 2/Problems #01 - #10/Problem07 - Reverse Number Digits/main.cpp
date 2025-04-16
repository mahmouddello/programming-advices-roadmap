#include <iostream>
#include <string>

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

int ReverseNumber(int number)
{

	/*
	Assume number is 1234

	1st iteration:
		reminder = number % 10 = 1234 % 10 = 4
		number = number / 10 = 1234 / 10 = 123
		revNumber = 0 * 10 + 4 = 4

	2nd iteration:
		reminder = number % 10 = 123 % 10 = 3
		number = number / 10 = 123 / 10 = 12
		revNumber = 4 * 10 + 3 = 43

	3rd iteration:
		reminder = number % 10 = 12 % 10 = 2
		number = number / 10 = 12 / 10 = 1
		revNumber = 43 * 10 + 2 = 432

	4th iteration:
		reminder = number % 10 = 1 % 10 = 1
		number = number / 10 = 1 / 10 = 0
		revNumber = 432 * 10 + 1 = 4321
*/

	int remainder = 0, revNumber = 0;

	while (number > 0)
	{
		remainder = number % 10;
		number = number / 10;

		revNumber = revNumber * 10 + remainder;
	}

	return revNumber;
}

void PrintReversedNumber(int reversedNumber)
{
	cout << "Reversed Number is: \n";
	cout << reversedNumber << endl;
}

int main()
{
	PrintReversedNumber(ReverseNumber(ReadPositiveNumber("Please enter a positive number: ")));
}