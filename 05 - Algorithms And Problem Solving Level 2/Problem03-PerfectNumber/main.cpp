#include <iostream>

using namespace std;


// Perfect Number = Sum (all divisors) مجموع قواسمه يساويه
// 28 = 1 + 2 + 4 + 7 + 14
// 6 = 1 + 2 + 3

// 28 : (2 + 4 + 7 + 14 + 1 = 28) Perfect
// 12 : Not Perfect (1 + 2 + 3 + 4 + 6 != 12)

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

void PrintResults(int number)
{
	if (isPerfectNumber(number))
		cout << "The number " << number << " is a perfect number! \n" << endl;

	else
		cout << "The number " << number << " is not a perfect number! \n" << endl;
}

int main()
{
	PrintResults(ReadPositiveNumber("Please enter a positive number: "));
}