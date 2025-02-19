#include <iostream>
using namespace std;

// palidrome is a number that reads the same from right to left

// solution: use reverse number function, if the number equals the reversed number
// it's a palindrome.

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

int ReverseNumber(int number)
{

	int remainder = 0, revNumber = 0;

	while (number > 0)
	{
		remainder = number % 10;
		number = number / 10;

		revNumber = revNumber * 10 + remainder;
	}

	return revNumber;
}

bool IsPalindrome(int number)
{
	return number == ReverseNumber(number);
}

int main()
{
	int number = ReadPositiveNumber("Please enter a positive number: ");

	if (IsPalindrome(number))
		cout << "Yes, it's a palindrome number.";
	else
		cout << "NO, it's NOT a palindrome number.";

	return 0;
}