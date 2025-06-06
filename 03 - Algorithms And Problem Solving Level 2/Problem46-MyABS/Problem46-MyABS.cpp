#include <iostream>
#include <cmath>

using namespace std;

int ReadNumber(string Message)
{
	int Number = 0;

	cout << Message << endl;
	cin >> Number;

	return Number;
}

int MyAbsFunction(int number)
{
	if (number > 0)
		return number;

	return number * -1;
}

int main()
{
	int number = ReadNumber("Please enter a number: ");

	cout << "My abs Result: " << MyAbsFunction(number) << endl;
	cout << "C++ abs Result: " << abs(number) << endl;

	return 0;
}