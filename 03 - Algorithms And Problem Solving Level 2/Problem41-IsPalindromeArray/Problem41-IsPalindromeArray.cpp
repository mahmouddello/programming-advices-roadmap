#include <iostream>

using namespace std;

bool isPalindromeArray(int array[10], const int& arrayLen)
{
	for (int i = 0; i < arrayLen / 2; i++)
	{
		if (array[i] != array[arrayLen - i - 1])
		{
			cout << array[i] << " & " << array[arrayLen - i - 1] << endl;
			return false;
		}

	}

	return true;
}

void PrintArray(int array[100], const int& length)
{

	for (int i = 0; i < length; i++)
		cout << array[i] << " ";

	cout << "\n";
}

int main()
{
	int arraySoruce[] = { 10, 20, 30, 30, 20, 10};
	int arraySourceLen = sizeof(arraySoruce) / sizeof(int);

	cout << "Array Elements:\n";
	PrintArray(arraySoruce, arraySourceLen);

	if (!isPalindromeArray(arraySoruce, arraySourceLen))
	{
		cout << "\nSorry, the array is not a palindrome array." << endl;
	}

	else
		cout << "\nYes, this array is a palindrome one." << endl;
}