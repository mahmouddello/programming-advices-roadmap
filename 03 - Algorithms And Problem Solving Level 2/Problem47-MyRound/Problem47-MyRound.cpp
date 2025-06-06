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

int MyRound(float number)
{
	int integerPart = int(number); // 10.3 becomes -> 10 

	// instead of checking for +0.5 and -0.5, we took abs to summarize.
	if (abs(GetFractionPart(number)) > 0.5)
	{
		if (number > 0) // if it was 10.3, we skip here and return the integer part 10;
			return ++integerPart;
		else
			return --integerPart;
	}

	else
	{
		return integerPart;
	}
}

int main()
{
	float number = ReadNumber("Please enter a number to round? ");

	cout << "My Round Function: " << MyRound(number) << endl;
	cout << "C++ Round function: " << round(number) << endl;

	return 0;
}