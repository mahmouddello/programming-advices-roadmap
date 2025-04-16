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

void CountAllDigitsFrequncies(int number)
{
	for (int i = 0; i <= 9; i++) // trying all possible digits from 0 - 9
	{
		short digitFreq = CountDigitFrequency(i, number);

		if (digitFreq > 0)
			cout << "Digit " << i << " frequency is " << digitFreq << " time(s)." << endl;

	}
}

int main()
{

	int number = ReadPositiveNumber("Please enter the main number: ");
	CountAllDigitsFrequncies(number);

	return 0;

}