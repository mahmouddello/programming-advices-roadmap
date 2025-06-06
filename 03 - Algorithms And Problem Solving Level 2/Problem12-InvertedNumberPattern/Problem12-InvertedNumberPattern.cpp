#include <iostream>

using namespace std;

/*
	GOAL: Prinint a number pattern but inverted

	EXAMPLE:

	Please enter a positive number: 5
	5 5 5 5 5
	4 4 4 4
	3 3 3
	2 2
	1
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

void PrintIvertedPattern(int number)
{
	for (int i = number; i > 0; i--)
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
	
	PrintIvertedPattern(ReadPositiveNumber("Please enter a positive number: "));

	return 0;
}