#pragma warning(disable : 4996)

#include <iostream>
#include <ctime>
#include "../mylibs/headers/date_utils.h"

using namespace std;
using date_utils::stDate;

/*
	Write a program to read a date and make functions as follows:
	• Overload the bayOfWeekOrder to take date structure
	• ISEndOfWeek
	• IsWeekEnd
	• IsBusinessbay
	• baysUntilTheEndOfWeek
	• baysUntilTheEndOfMonth
	• DaysUntiITheEndOfYear
*/

stDate getSystemDate()
{
	stDate todayDate;
	time_t t = time(0); // get time now
	tm* now = localtime(&t);

	todayDate.year = now->tm_year + 1900;
	todayDate.month = now->tm_mon + 1;
	todayDate.day = now->tm_mday;

	return todayDate;
}

short dayOfWeekOrder(stDate date)
{
	return date_utils::dayOfWeekOrder(date.year, date.month, date.day);
}

bool isEndOfWeek(short dayOrder)
{
	return date_utils::dayShortName(dayOrder) == "Sat";
}

bool isWeekend(short dayOrder)
{
	string dayStr = date_utils::dayShortName(dayOrder);

	return dayStr == "Fri" || dayStr == "Sat";
}

bool isBusinessDay(short dayOrder)
{
	return !isWeekend(dayOrder);
}

short daysUntilEndOfTheWeek(short dayOrder)
{
	short counter = 0;

	while (date_utils::dayShortName(dayOrder) != "Sat")
	{
		counter++;
		dayOrder++;
	}

	return counter;

	// or : return 6 - dayOrder [6 indecies for 7 days, day order is from 0 - 6]
}

short daysUntilEndOfTheMonth(stDate date)
{
	short monthDays = date_utils::numberOfDaysInAMonth(date.year, date.month);
	stDate endDate{ monthDays, date.month, date.year };

	return date_utils::differenceInDays(date, endDate, true);
}

short daysUntilEndOfTheYear(stDate date)
{
	stDate yearEndDate{ 31, 12, date.year };

	return date_utils::differenceInDays(date, yearEndDate, true);
}

int main()
{

	stDate date{ 2, 10, 2022 };
	short dayOrder = dayOfWeekOrder(date);

	cout << "Today is " << date_utils::dayShortName(dayOrder);
	cout << ", " << date.day << "/" << date.month << "/" << date.year << endl;

	cout << "\nIs it end of the week?" << endl;

	if (!isEndOfWeek(dayOrder))
	{
		cout << "No it's not the end of the week." << endl;
	}
	else
	{
		cout << "Yes it's the end of the week." << endl;
	}

	cout << "\nIs it weekend?" << endl;

	if (!isWeekend(dayOrder))
	{
		cout << "No it's not weekend." << endl;
	}
	else
	{
		cout << "Yes it's weekend." << endl;
	}

	cout << "\nIs it business day?" << endl;

	if (!isBusinessDay(dayOrder))
	{
		cout << "No it's not a business day." << endl;
	}
	else
	{
		cout << "Yes it's a business day." << endl;
	}

	cout << "\nDays until the end of the week: " << daysUntilEndOfTheWeek(dayOrder) << " Day(s)." << endl;
	cout << "\nDays until the end of the month: " << daysUntilEndOfTheMonth(date) << " Day(s)." << endl;
	cout << "\nDays until the end of the year: " << daysUntilEndOfTheYear(date) << " Day(s)." << endl;


	return 0;
}