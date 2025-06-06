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

int FindNumberIndex(int array[100], const int& length, int& numberToSearch)
{
	numberToSearch = ReadPositiveNumber("Please enter number to search for? ");

	for (int i = 0; i < length; i++)
		if (numberToSearch == array[i])
			return i; // return index i if found

	return -1; // return -1 if not found
}

bool IsNumberInArray(int array[100], const int& length, int& numberToSearch)
{
	return FindNumberIndex(array, length, numberToSearch) != -1;
}

int main()
{

	srand((unsigned)time(NULL)); // random seed, called only once

	int array[100], length, numberToSearch = 0;

	FillArrayWithRandomNumbers(array, length);

	cout << "\nArray Elements:\n";
	PrintArray(array, length);

	cout << "\nThe number you are looking for: " << numberToSearch << endl;

	if (IsNumberInArray(array, length, numberToSearch))
	{
		cout << "\nYes the number was found :)" << endl;
	}

	else
		cout << "\nThe number was not found in the array :(" << endl;

	return 0;
}
