#include <iostream>

using namespace std;

// GOAL: Print a letter pattern

// EXAMPLE: 
//// Please enter a positive number:
//5
//A
//B B
//C C C
//D D D D
//E E E E E

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

void PrintLatterPattern(int number)
{
	for (int i = 1; i <= number; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << char(64 + i) << " ";
		}

		cout << "\n";
	}
}

void ProgrammingAdvices(int number)
{
	for (int i = 65; i <= 65 + number - 1; i++)
	{
		for (int j = 1; j <= i - 65 + 1; j++)
		{
			cout << char(i) << " ";
		}

		cout << "\n";
	}
			
}

int main()
{
	PrintLatterPattern(ReadPositiveNumber("Please enter a positive number: "));

	ProgrammingAdvices(ReadPositiveNumber("Please enter a positive number: "));

	return 0;
}