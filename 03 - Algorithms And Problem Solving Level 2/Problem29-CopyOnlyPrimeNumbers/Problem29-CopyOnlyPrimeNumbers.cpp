#include <iostream>

using namespace std;

enum enPrimeStatus { Prime = 1, NotPrime = 2 };

enPrimeStatus CheckPrime(int number)
{

	if (number < 2)
		return enPrimeStatus::NotPrime;

	/*
		
		Any factor of number larger than sqrt(number) must be paired with a factor smaller than sqrt(number),
		so checking up to sqrt(number) is sufficient.
		This makes the function more efficient compared to checking up to number / 2.
		Now, CheckPrime(53) will correctly return Prime.
		
	*/

	int M = sqrt(number);

	for (int i = 2; i <= M; i++)
		if (number % i == 0)
			return enPrimeStatus::NotPrime;

	return enPrimeStatus::Prime;
}

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
		arr[i] = RandomNumber(1, 100);
	}
}

void PrintArray(int array[100], const int& length)
{

	for (int i = 0; i < length; i++)
		cout << array[i] << " ";

	cout << "\n";
}

void CopyPrimeNumsToArray(int arr1[100], int arr2[100], const int& arr1Len, int& arr2Len)
{

	for (int i = 0; i < arr1Len; i++)
	{
		if (CheckPrime(arr1[i]) == enPrimeStatus::Prime)
		{
			arr2[arr2Len] = arr1[i];
			arr2Len++;
		}
	}
}

int main()
{
	srand((unsigned)time(NULL)); // random seed

	int originalArray[100], newArray[100];
	int originalArrLength, newArrayLength = 0;

	FillArrayWithRandomNumbers(originalArray, originalArrLength); // array and length values changed

	cout << "Original Array: ";
	PrintArray(originalArray, originalArrLength);

	CopyPrimeNumsToArray(originalArray, newArray, originalArrLength, newArrayLength); // copy

	cout << "Prime Numbers in New Array: ";
	PrintArray(newArray, newArrayLength);

	return 0;
}