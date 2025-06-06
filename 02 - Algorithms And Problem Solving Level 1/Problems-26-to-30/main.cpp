#include <iostream>

using namespace std;

// Problem Solution in order, from #26 to #30, Read_N will be used in all problems.

// ------- Problem #26 - Print Numbers from 1 to N  -------

int Read_N()
{
	int N;

	cout << "Enter the value of N: ";
	cin >> N;

	return N;

}

void PrintNumbersFromOnetoN(int N)
{
	for (int i = 1; i <= N; i++)
		cout << i << endl;
}

// ------- Problem #27 - Print Numbers from N to 1  -------

void PrintNumbersFromNtoOne(int N)
{
	for (N; N >= 1; N--)
		cout << N << endl;
}

// ------- Problem #28 - Print Sum Odd Numbers from 1 to N -------

enum enEvenOddState { Even = 0, Odd = 1 };

enEvenOddState CheckNumberOddorEven(int N)
{
	if (N % 2 == 0)
		return enEvenOddState::Even;

	return enEvenOddState::Odd;
}

int SumOfOddNumbers(int N)
{
	int sum = 0;

	for (int i = 1; i <= N; i++)
		if (CheckNumberOddorEven(i) == enEvenOddState::Odd)
			sum += i;

	return sum;
}

// ------- Problem #29 - Print Sum Even Numbers from 1 to N -------

int SumOfEvenNumbers(int N)
{
	int sum = 0;

	for (int i = 1; i <= N; i++)
		if (CheckNumberOddorEven(i) == enEvenOddState::Even)
			sum += i;

	return sum;
}

// ------- Problem #30 - Factorial of N! -------

int FactorialOfN(int N)
{
	int factorial = 1;

	for (N; N >= 1; N--)
		factorial *= N;

	return factorial;

}

int main()
{
	int N = Read_N();

	PrintNumbersFromOnetoN(N);
	PrintNumbersFromNtoOne(N);
	cout << "Sum of odd numbers from 1 to " << N << ": " << SumOfOddNumbers(N) << endl;
	cout << "Sum of even numbers from 1 to " << N << ": " << SumOfEvenNumbers(N) << endl;
	cout << "Factorial of " << N << " = " << FactorialOfN(N);

}
