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

void GenerateOrderdArray(int array[100], const int& length)
{
	for (int i = 0; i < length; i++)
		array[i] = i + 1;
}

void PrintArray(int array[100], const int& length)
{

	for (int i = 0; i < length; i++)
		cout << array[i] << " ";

	cout << "\n";
}

void ShuffleArrayElements(int array[100], const int& length)
{
	for (int i = 0; i < length; i++)
	{
		int randomIndex = RandomNumberInRange(1, length - 1); //

		cout << i + 1 << ". iteration, number to swap is: " << array[i] << endl;
		cout << "Random Index is: " << randomIndex << endl;
		cout << "Swapping " << array[i] << " with: " << array[randomIndex] << endl;

		Swap2Numbers(array[i], array[randomIndex]);

		cout << "-----------------------------------";

		cout << "\nNew Arr:\n";
		PrintArray(array, length);
		cout << "\n" << endl;
		
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int array[100], length;

	length = ReadPositiveNumber("Please enter the length of the array: ");

	GenerateOrderdArray(array, length);

	cout << "\nArray before shuffle:\n";
	PrintArray(array, length);
	cout << "\n\n";

	ShuffleArrayElements(array, length);

	cout << "\nArray after shuffle:\n";
	PrintArray(array, length);

	return 0;
}