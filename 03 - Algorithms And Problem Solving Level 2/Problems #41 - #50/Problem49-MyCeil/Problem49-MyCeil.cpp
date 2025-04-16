#include <iostream>
#include <cmath>

using namespace std;

float ReadNumber(string Message)
{
	float Number = 0;

	cout << Message << endl;
	cin >> Number;

	return Number;
}

float GetFractionPart(float number)
{
	return number - int(number); // e.g. : 10.3 - 10 = 0.3
}

int MyCeil(float number)
{
	int integerPart = int(number);

	if (GetFractionPart(number) <= 0)
		return integerPart;

	return ++integerPart;
}

int main()
{
	float number = ReadNumber("Enter a number: ");

	cout << "My ceil: " << MyCeil(number) << endl;
	cout << "C++ Ceil: " << ceil(number) << endl;

	return 0;
}