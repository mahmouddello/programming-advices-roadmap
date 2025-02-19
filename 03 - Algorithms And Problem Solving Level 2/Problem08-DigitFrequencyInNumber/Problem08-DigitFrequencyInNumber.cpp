#include <iostream>
using namespace std;

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

int CountDigitFrequency(short digitToCheck, int number)
{
	int freqCount = 0, remainder = 0;
	while (number > 0)
	{
		remainder = number % 10; // getting the digit in ones place
		number = number / 10; // dividing by 10 to remove the digit in ones place
		if (digitToCheck == remainder)
			freqCount++;
	}

	return freqCount;
}

int main()
{
	int number = ReadPositiveNumber("Please enter the main number: ");
	short digitToCheck = ReadPositiveNumber("Please enter the digit: ");

	cout << "\nDigit " << digitToCheck << " frequency is "
		<< CountDigitFrequency(digitToCheck, number) << " Time(s).\n" << endl;

}