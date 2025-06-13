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

void FillArrayWithRandomNumbers(int arr[100], const int& length)
{

	for (int i = 0; i < length; i++)
	{
		arr[i] = RandomNumber(1, 100);
	}
}

void SumOf2Arrays(int arr1[100], int arr2[100], int sumArray[100], const int& length)
{
	for (int i = 0; i < length; i++)
		sumArray[i] = arr1[i] + arr2[i];
}

void PrintArray(int array[100], const int& length)
{

	for (int i = 0; i < length; i++)
		cout << array[i] << " ";

	cout << "\n";
}

int main()
{
	srand((unsigned)time(NULL));
	
	int arr1[100], arr2[100], sumArray[100];
	int length = ReadPositiveNumber("How many numbers you want to generate? ");

	FillArrayWithRandomNumbers(arr1, length); // filling first array with random numbers

	FillArrayWithRandomNumbers(arr2, length); // filling first array2 with random numbers

	cout << "\nArray 1:\n";
	PrintArray(arr1, length);

	cout << "\nArray 2:\n";
	PrintArray(arr2, length);

	SumOf2Arrays(arr1, arr2, sumArray, length);

	cout << "\nSum of arr1 and arr2:\n";
	PrintArray(sumArray, length);

	return 0;
}