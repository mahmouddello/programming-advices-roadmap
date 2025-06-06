#include <iostream>

using namespace std;

enum enPrimeNotPrime { NotPrime = 1, Prime = 2 };

enPrimeNotPrime isPrime(int number)
{
	if (number < 2)
		return enPrimeNotPrime::NotPrime;

	for (int i = 2; i < number; i++)
	{
		if (number % i == 0)
			return enPrimeNotPrime::NotPrime;
	}

	return enPrimeNotPrime::Prime;
}

int ReadPositiveNumber(string Message)
{
	int Number = 0;
	do
	{
		cout << Message;
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

void AddArrayElement(int number, int arrDest[100], int& arrDestLen)
{
	arrDestLen++;
	arrDest[arrDestLen - 1] = number;
}

void CopyPrimeNumsUsingAddArrayElements(int arrSrc[100], const int& arrSrcLen, int arrDest[100], int& arrDestLen)
{
	for (int i = 0; i < arrSrcLen; i++)
		if (isPrime(arrSrc[i]) == enPrimeNotPrime::Prime)
			AddArrayElement(arrSrc[i], arrDest, arrDestLen);
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

	int arraySource[100], arraySourceLen = 0;
	int arrayDest[100], arrayDestLen = 0;

	FillArrayWithRandomNumbers(arraySource, arraySourceLen);

	cout << "Array Source Elements: ";
	PrintArray(arraySource, arraySourceLen);

	CopyPrimeNumsUsingAddArrayElements(arraySource, arraySourceLen, arrayDest, arrayDestLen);

	cout << "Array Destination Prime Elements: ";
	PrintArray(arrayDest, arrayDestLen);

	return 0;
}