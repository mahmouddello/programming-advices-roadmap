#include <iostream>
#include "clsInputValidate.h"

using namespace std;

int main()
{

	cout << clsInputValidate::isNumberBetween(5, 1, 10) << endl;
	cout << clsInputValidate::isNumberBetween(5.5, 1.3, 10.8) << endl;

	cout << clsInputValidate::isDateBetween(clsDate(), clsDate(1, 5, 2025), clsDate(31, 5, 2025)) << endl;
	cout << clsInputValidate::isDateBetween(clsDate(), clsDate(31, 5, 2025), clsDate(1, 5, 2025)) << endl;
	cout << clsInputValidate::isDateBetween(clsDate(), clsDate(30, 4, 2025), clsDate(1, 3, 2025)) << endl;

	int x = clsInputValidate::readIntNumber("Invalid number, enter another one: ");
	cout << "X = " << x << endl;

	double y = clsInputValidate::readDoubleNumber("Invalid number, enter another one: ");
	cout << "Y = " << y << endl;

	int z = clsInputValidate::readIntNumberBetween(1, 5, "Number is not within range, try again: ");
	cout << "Z = " << z << endl;

	double c = clsInputValidate::readDoubleNumberBetween(1, 5, "Number is not within range, try again: ");
	cout << "C = " << c << endl;

	cout << clsInputValidate::isDateValid(clsDate(35, 12, 2022)) << endl;
	cout << clsInputValidate::isDateValid(clsDate(24, 5, 2022)) << endl;

	return 0;
}