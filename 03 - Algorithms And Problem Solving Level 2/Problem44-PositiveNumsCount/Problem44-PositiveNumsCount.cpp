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

int RandomNumber(int from, int to)
{

	/*
		For example, if you want numbers between 3 and 7:

		(7 - 3 + 1) = 5, so rand() % 5 gives numbers from 0 to 4.
		Adding 3 shifts it to 3 to 7.
	*/

	int randomNumber = rand() % (to - from + 1) + from;

	return randomNumber;
}

void FillArrayWithRandomNumbers(int arr[100], int& length)
{
	length = ReadPositiveNumber("How many numbers you want to generate? ");

	for (int i = 0; i < length; i++)
	{
		arr[i] = RandomNumber(-100, 100);
	}
}

int CountPositiveNums(int arr[100], const int& length)
{
	int count = 0;

	for (int i = 0; i < length; i++)
		if (arr[i] > 0)
			count++;

	return count;
}

void PrintArray(int array[100], const int length)
{

	for (int i = 0; i < length; i++)
		cout << array[i] << " ";

	cout << "\n";
}

int main()
{
	srand((unsigned)time(NULL));

	int array[100], arrayLen = 0;

	FillArrayWithRandomNumbers(array, arrayLen);

	cout << "Array Elements:\n";
	PrintArray(array, arrayLen);

	cout << "\nPositive numbers count is: " << CountPositiveNums(array, arrayLen) << endl;

	return 0;
}