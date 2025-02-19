#include <iostream>

using namespace std;

enum enPrimeStatus {Prime = 1, NotPrime = 2};

int ReadUpperRange()
{
	// Read the positive upper range to show all prime number in that range

	int range;

	do {
		cout << "Please enter the upper range: ";
		cin >> range;
	} while (range <= 0);

	return range;
}

enPrimeStatus CheckPrime(int number)
{

	if (number == 1)
		return enPrimeStatus::NotPrime;

	// To improve the performance of the code, 
	// we divide the number by 2 because if the number is divisible evenly by its half,
	// there is no need to check the division of the number for prime status.

	int M = round(number / 2);

	for (int i = 2; i <= M; i++)
		if (number % i == 0)
			return enPrimeStatus::NotPrime;

	return enPrimeStatus::Prime;
}

void PrintPrimeNumbersInRange(int upperRange)
{

	cout << "Prime Numbers in range from 1 to " << upperRange << " are: " << endl;

	for (int number = 1; number <= upperRange; number++)
		if (CheckPrime(number) == enPrimeStatus::Prime)
			cout << number << endl;
}

int main()
{
	PrintPrimeNumbersInRange(ReadUpperRange());
}
