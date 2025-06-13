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

int getNumberOfDays(short year)
{
	return isLeapYear(year) ? 366 : 365;
}

int getNumberOfHours(short year)
{
	return getNumberOfDays(year) * 24;
}

int getNumberOfMinutes(short year)
{
	return getNumberOfHours(year) * 60;
}

int getNumberOfSeconds(short year)
{
	return getNumberOfMinutes(year) * 60;
}

int main()
{

	short year = readYear();

	cout << "Number of days for year [" << year << "] is: " << getNumberOfDays(year) << endl;
	cout << "Number of hours for year [" << year << "] is: " << getNumberOfHours(year) << endl;
	cout << "Number of minutes for year [" << year << "] is: " << getNumberOfMinutes(year) << endl;
	cout << "Number of seconds for year [" << year << "] is: " << getNumberOfSeconds(year) << endl;

	return 0;
}