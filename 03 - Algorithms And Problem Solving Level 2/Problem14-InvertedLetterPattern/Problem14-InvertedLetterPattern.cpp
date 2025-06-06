#include <iostream>

using namespace std;

/*
	GOAL: Prinint a letter pattern but inverted

	EXAMPLE:

	Please enter a positive number: 4
	D D D D
	C C C
	B B
	A
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

void PrintIvertedLetterPattern(int number)
{
	for (int i = number; i > 0; i--)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << char(64 + i) << " ";
		}

		cout << "\n";
	}
}

int main()
{

	PrintIvertedLetterPattern(ReadPositiveNumber("Please enter a positive number: "));

	return 0;
}