#include <iostream>

using namespace std;

/*
	GOAL: Prinint a number pattern

	EXAMPLE: 
	Please enter a positive number: 5
	1
	2 2
	3 3 3
	4 4 4 4
	5 5 5 5 5
*/

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

void PrintNumberPattern(int number)
{
	for (int i = 1; i <= number; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << i << " ";
		}

		cout << "\n";
	}
}

int main()
{

	PrintNumberPattern(ReadPositiveNumber("Please enter a positive number: "));

	return 0;
}