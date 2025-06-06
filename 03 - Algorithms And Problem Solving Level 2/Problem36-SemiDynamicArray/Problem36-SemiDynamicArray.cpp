#include <iostream>

using namespace std;

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

void InputArrayElements(int array[100], int& arrLength)
{
	int number = 0; // temporary number
	bool choice = 0;

	for (int i = 0; i < 100; i++)
	{
		number = ReadPositiveNumber("Please enter a number: ");
		array[i] = number;
		arrLength++;

		cout << "Do you want to add more numbers? [0]: No, [1]: Yes? ";
		cin >> choice;

		if (!choice)
			return;
	}
}

void PrintArray(int array[100], const int& length)
{

	for (int i = 0; i < length; i++)
		cout << array[i] << " ";

	cout << "\n";
}

int main()
{
	int array[100], arrLength = 0; // arrLength will be set later

	InputArrayElements(array, arrLength);

	cout << "\nArray Length: " << arrLength << endl;
	
	cout << "\nArray Elements: ";
	PrintArray(array, arrLength);

	return 0;
}