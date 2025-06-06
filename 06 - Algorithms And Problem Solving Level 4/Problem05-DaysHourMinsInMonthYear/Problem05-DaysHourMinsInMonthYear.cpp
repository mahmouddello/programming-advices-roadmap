#include <iostream>

using namespace std;

bool isLeapYear(short year)
{
	return ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
}

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

short NumberOfDaysInAMonthV2(short Month, short Year)
{
	if (Month < 1 || Month>12)
		return 0;
	if (Month == 2)
	{
		return isLeapYear(Year) ? 29 : 28;
	}
	short arr31Days[7] = { 1,3,5,7,8,10,12 };
	for (short i = 1; i <= 7; i++)
	{
		if (arr31Days[i - 1] == Month)
			return 31;
	}
	//if you reach here then its 30 days.
	return 30;
}

int getNumberOfDaysInMonth(short year, short month)
{
	short monthDays[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	
	return (isLeapYear(year) && month == 2) ? monthDays[month - 1] + 1 : monthDays[month - 1];
}

int getNumberOfHoursInMonth(short year, short month)
{
	return getNumberOfDaysInMonth(year, month) * 24;
}

int getNumberOfMinutesInMonth(short year, short month)
{
	return getNumberOfHoursInMonth(year, month) * 60;
}

int getNumberOfSecondsInMonth(short year, short month)
{
	return getNumberOfMinutesInMonth(year, month) * 60;
}

int main()
{
	short year = readYear();
	short month = readMonth();

	cout << "Number of days for year [" << month << "] is: " << getNumberOfDaysInMonth(year, month) << endl;
	cout << "Number of hours for year [" << month << "] is: " << getNumberOfHoursInMonth(year, month) << endl;
	cout << "Number of minutes for year [" << month << "] is: " << getNumberOfMinutesInMonth(year, month) << endl;
	cout << "Number of seconds for year [" << month << "] is: " << getNumberOfSecondsInMonth(year, month) << endl;

	return 0;
}