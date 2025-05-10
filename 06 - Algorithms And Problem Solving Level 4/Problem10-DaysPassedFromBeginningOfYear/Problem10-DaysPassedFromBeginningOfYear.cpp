#include <iostream>
#include "../mylibs/headers/date_utils.h"

using namespace std;

short numberOfDaysFromBeginningOfTheYear(const short year, const short month, const short day)
{
	short totalDays = 0;

	for (short monthIndex = 1; monthIndex < month; monthIndex++)
	{
		totalDays += date_utils::numberOfDaysInAMonth(year, monthIndex);
	}

	totalDays += day;

	return totalDays;
}

int main()
{
	short day, month, year;

	day = date_utils::readDay();
	month = date_utils::readMonth();
	year = date_utils::readYear();

	cout << "Number of days from the beginning of the year is: "; 
	cout << numberOfDaysFromBeginningOfTheYear(year, month, day) << endl;

	return 0;
}