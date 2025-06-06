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

int MyFloor(float number)
{
	int integerPart = int(number);

	return (number >= 0) ? integerPart : (number == integerPart ? integerPart : integerPart - 1);

}

int main()
{
	float number = ReadNumber("Enter a number: ");

	cout << "My Floor: " << MyFloor(number) << endl;
	cout << "C++ Floor: " << floor(number) << endl;

	return 0;
}