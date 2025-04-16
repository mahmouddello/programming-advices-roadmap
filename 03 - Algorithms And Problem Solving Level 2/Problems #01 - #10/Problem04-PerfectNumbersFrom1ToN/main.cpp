#include <iostream>

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

bool isPerfectNumber(int number)
{
	// summing the dividors, and check if the sum is equal to the number itself.

	int sum = 0;

	for (int i = 1; i < number; i++)
		if (number % i == 0)
			sum += i;

	return number == sum;
}

void PrintPerfectNumbersFrom1ToN(int upperRange)
{
	for (int i = 1; i <= upperRange; i++)
		if (isPerfectNumber(i))
			cout << i << endl;
}

int main()
{
	PrintPerfectNumbersFrom1ToN(ReadPositiveNumber("Enter the upper range (N): "));
}
