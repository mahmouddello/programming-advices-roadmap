#include <iostream>
#include <string>

using namespace std;

int ReadPositiveNumber(string message)
{
	int number = 0;

	do {
		cout << message;
		cin >> number;

	} while (number <= 0);

	return number;
}

// Divider
void PrintDivider()
{
	cout << "-------------------------------" << endl;
}

// My Solution
void PrintDigits_Me(int number)
{
	string numberStr = to_string(number);        // Convert the number to a string
	int numberStrLength = numberStr.length();   // Get the string length

	for (int i = numberStrLength - 1; i >= 0; i--)  // Iterate from the end of the string
	{
		cout << numberStr[i] << endl;           // Print each character
	}
}

// Programming Advices
void PrintDigits_ProgrammingAdvices(int number)
{
	int reminder;

	while (number > 0)
	{
		reminder = number % 10;
		cout << reminder << endl;
		number = number / 10;
	}

	/*
		Assume number is 1234
		
		1st iteration: 
			reminder = number % 10 = 1234 % 10 = 4
			number = number / 10 = 1234 / 10 = 123

		2nd iteration:
			reminder = number % 10 = 123 % 10 = 3
			number = number / 10 = 123 / 10 = 12

		3rd iteration:
			reminder = number % 10 = 12 % 10 = 2
			number = number / 10 = 12 / 10 = 1

		4th iteration: 
			reminder = number % 10 = 1 % 10 = 1
			number = number / 10 = 1 / 10 = 0
	*/
}

int main()
{
	PrintDigits_Me(ReadPositiveNumber("Please enter a positive number: "));

	PrintDivider();

	PrintDigits_ProgrammingAdvices(ReadPositiveNumber("Please enter a positive number: "));
}