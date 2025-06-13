#include <iostream>

using namespace std;

void PrintNumbers(int from, int to) {

	if (from <= to) {
		cout << from << endl;
		PrintNumbers(from + 1, to);
	}
}

void PrintNumbersReversed(int m, int n)
{
	if (m >= n)
	{
		cout << m << endl;
		PrintNumbersReversed(m - 1, n);
	}
}

int PowerOfNumber(int n, const int& m, int& counter)
{
	
	static int result = 1;
	
	if (counter <= m)
	{
		result = result * n;
		counter++;

		PowerOfNumber(n, m, counter);
	}

	return result;
}

int MyPower(int Base, int Power)
{
	if (Power == 0)
		return 1;

	return Base * MyPower(Base, Power - 1);
}

int main() {

	int n = 2, m = 3, counter = 1;
	
	cout << PowerOfNumber(n, m, counter) << endl;
	cout << MyPower(2, 4) << endl;

	return 0;
}