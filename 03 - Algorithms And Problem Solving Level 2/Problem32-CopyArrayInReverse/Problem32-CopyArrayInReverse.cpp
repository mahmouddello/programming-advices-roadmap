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

int RandomNumberInRange(int from, int to)
{
	return rand() % (to - from + 1) + from;
}

void Swap2Numbers(int& firstNum, int& secondNum)
{
	int temp = firstNum;
	firstNum = secondNum;
	secondNum = temp;
}

void FillArrayWithRandomNumbers(int arr[100], int& length)
{
	length = ReadPositiveNumber("How many numbers you want to generate? ");

	for (int i = 0; i < length; i++)
	{
		arr[i] = RandomNumberInRange(1, 100);
	}
}

void CopyArrayInReverse(int originalArray[100], int newArray[100], const int& length)
{
	for (int i = 0; i < length; i++)
		newArray[i] = originalArray[length - i - 1]; // copying elements to the new array
}

void PrintArray(int array[100], const int& length)
{

	for (int i = 0; i < length; i++)
		cout << array[i] << " ";

	cout << "\n";
}

int main()
{
	srand((unsigned)time(NULL)); // random seed

	int originalArray[100], newArray[100];
	int originalArrLength;

	FillArrayWithRandomNumbers(originalArray, originalArrLength); // array and length values changed

	cout << "\nOriginal Array:\n";
	PrintArray(originalArray, originalArrLength);

	CopyArrayInReverse(originalArray, newArray, originalArrLength);

	cout << "\nNew Array after copying in reversed order:\n";
	PrintArray(newArray, originalArrLength);

	return 0;
}