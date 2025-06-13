#include <iostream>
#include "../mylibs/headers/date_utils.h"

using namespace std;
using date_utils::stDate;

stDate increaseDateByOneDay(stDate date)
{
	if (date_utils::isLastDayInMonth(date) && !date_utils::isLastMonthInYear(date.month))
	{
		date.day = 1;
		date.month++;
	}

	else if (date_utils::isLastDayInMonth && date_utils::isLastMonthInYear(date.month))
	{
		date.day = 1;
		date.month = 1;
		date.year++;
	}
	
	else
	{
		date.day++;
	}

	return date;
}

// from comments
stDate getDateAfterOneDay(stDate date)
{
	date.day++;

	if (date.day > date_utils::numberOfDaysInAMonth(date.year, date.month))
	{
		date.day = 1;
		date.month++;

		if (date.month > 12) 
		{
			date.month = 1;
			date.year++;
		}
	}

	return date;
}

int main()
{
	stDate date = date_utils::readFullDate();

	date = _AGLOBAL::increaseDateByOneDay(date);

	cout << "Date after adding one day is: ";
	printf("%d/%d/%d\n", date.day, date.month, date.year);

	return 0;
}