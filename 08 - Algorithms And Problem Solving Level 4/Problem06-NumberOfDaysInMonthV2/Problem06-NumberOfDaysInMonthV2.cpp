#include <iostream>

// This problem solution is version 2 of Problem 05, but will be a shorter and more logical

using namespace std;

short readYear()
{
	short year;

	cout << "Please enter a year: ";
	cin >> year;

	cout << endl;

	return year;
}

short readMonth()
{
	short month;

	cout << "Please enter a month: ";
	cin >> month;

	cout << endl;

	return month;
}

bool isLeapYear(short year)
{
	return ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
}

short numberOfDaysInAMonth(const short year, const short month)
{
	if (month < 1 || month > 12)
		return 0;

	short monthDays[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	return month == 2 ? (isLeapYear(year) ? 29 : 28) : monthDays[month - 1];
}

short getDaysInMonthGPT(const short year, const short month)
{
	if (month < 1 || month > 12)
		return 0;

	bool monthDays[] = { 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1 }; // boolean only cosumes 1 byte in memory

	return month == 2 ? isLeapYear(year) ? 29 : 28 : monthDays[month - 1] + 30;
}

int main()
{
	short year = readYear();
	short month = readMonth();

	cout << "Number of days for month [" << month << "] is: " << numberOfDaysInAMonth(year, month) << endl;
	cout << "Number of days for month [" << month << "] is: " << getDaysInMonthGPT(year, month) << endl;

	return 0;
}