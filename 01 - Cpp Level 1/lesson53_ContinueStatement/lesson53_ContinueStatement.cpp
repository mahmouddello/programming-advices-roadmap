#include <iostream>

using namespace std;

int homework()
{
	// Read 5 numbers and sum them up as long as the number is below 50 use for
	// loop and continue statement.

	int number, sum = 0;

	for (int i = 1; i <= 5; i++)
	{
		cout << "Please enter a number: ";
		cin >> number;

		if (number >= 50)
			continue;

		sum += number;

	}

	return sum;

}

int main()
{

	cout << "Sum = " << homework() << endl;
	return 0;

}
