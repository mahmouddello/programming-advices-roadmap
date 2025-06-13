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

void ReadArray(int array[100], int& length)
{
	length = ReadPositiveNumber("Please enter array size / length: ");


	for (int i = 0; i < length; i++)
	{
		cout << "Element [" << i + 1 << "] : ";
		cin >> array[i];
 	}
}

void PrintArray(int array[100], const int length)
{
	
	cout << "Original Array: ";

	for (int i = 0; i < length; i++)
		cout << array[i] << " ";

	cout << "\n";
}

int CheckDigitFrequency(int array[100], const int length, int number)
{
	int counter = 0;

	for (int i = 0; i < length; i++)
	{
		if (number == array[i])
			counter++;
	}

	return counter;
}

int main()
{

	int array[100], arrLength;

	ReadArray(array, arrLength);

	int numberToCheck = ReadPositiveNumber("Please enter the number you want to check: ");

	CheckDigitFrequency(array, arrLength, numberToCheck);

	return 0;
}