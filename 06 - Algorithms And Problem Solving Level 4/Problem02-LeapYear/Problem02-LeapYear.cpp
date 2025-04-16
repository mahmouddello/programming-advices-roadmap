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
	if (year % 400 == 0)
		return true;

	else if (year % 4 == 0 && year % 100 != 0)
		return true;

	return false;
}

int main()
{
	

	short years[] = {1968, 1971, 2006, 2004, 1700, 1800, 1600, 2000, 2012};
	short yearsSize = sizeof(years) / sizeof(years[0]);

	for (short i = 0; i < yearsSize; i++)
	{
		if (isLeapYear(years[i]))
			cout << years[i] << " is a leap year." << endl;
		else
			cout << years[i] << " isn't a leap year." << endl;
	}

	short year = readYear();

	if (isLeapYear(year))
		cout << year << " is a leap year." << endl;
	else
		cout << year << " isn't a leap year." << endl;

	return 0;
}