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

float MySqrt(float number)
{
	return pow(number, (0.5));
}

int main()
{
	float number = ReadNumber("Please enter a number: ");

	cout << "MySqrt: " << MySqrt(number) << endl;
	cout << "C++ Sqrt: " << sqrt(number) << endl;

	return 0;
}