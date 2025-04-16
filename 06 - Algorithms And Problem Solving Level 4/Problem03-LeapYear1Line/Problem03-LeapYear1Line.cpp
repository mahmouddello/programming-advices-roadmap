#include <iostream>

using namespace std;

short readYear()
{
	short year;

	cout << "Please enter a year to check if it's leap or not: ";
	cin >> year;

	cout << endl;

	return year;
}

bool isLeapYear(short year)
{
	return ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
}

int main()
{

	short year = readYear();

	if (isLeapYear(year))
		cout << year << " is a leap year." << endl;
	else
		cout << year << " isn't a leap year." << endl;

	return 0;
}