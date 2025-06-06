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
		arr[i] = RandomNumber(1, 100);
	}
}

void PrintArray(int array[100], const int& length)
{

	for (int i = 0; i < length; i++)
		cout << array[i] << " ";

	cout << "\n";
}

int SumOfArrayElements(int array[100], const int& length)
{
	int sum = 0;

	for (int i = 0; i < length; i++)
	{
		sum += array[i];
	}

	return sum;
}

int main()
{
	// seeds the random number generator in c++, called only once.
	srand((unsigned)time(NULL));

	int arr[100], numberCount;

	FillArrayWithRandomNumbers(arr, numberCount);

	cout << "Array Elements: ";
	PrintArray(arr, numberCount);

	cout << "Sum of Array Elements: " << SumOfArrayElements(arr, numberCount) << endl;

	return 0;
}