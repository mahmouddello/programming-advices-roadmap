#include <iostream>
using namespace std;

// first we reverse number, then print it digits with % operator

int ReadPositiveNumber(string Message)
{
	int Number = 0;
	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}

int ReverseNumber(int number)
{

	int remainder = 0, revNumber = 0;

	while (number > 0)
	{
		remainder = number % 10;
		number = number / 10;

		revNumber = revNumber * 10 + remainder;
	}

	return revNumber;
}

void PrintDigits(int number)
{

	int reminder = 0;

	while (number > 0)
	{
		reminder = number % 10;
		number /= 10;
		cout << reminder << endl;
	}
}

int main()
{

	int number = ReadPositiveNumber("Please enter the main number: ");

	PrintDigits(ReverseNumber(number));

	return 0;
}