#include <iostream>
#include "../mylibs/headers/date_utils.h"
#include <cassert>

using date_utils::stDate;
using namespace std;

stDate decreaseDateByOneDay(stDate date)
{
	
	short monthDays = date_utils::numberOfDaysInAMonth(date.year, date.month);

	// incase of invalid date input like 35/1/2005 or 30/2/2022 or 29/2/2001 ...
	if (date.day > monthDays)
		date.day = monthDays;
	
	if (date.day == 1)
	{
		if (date.month == 1)
		{
			date.month = 12;
			date.day = 31;
			date.year--;
		}
		else
		{
			date.month--;
			date.day = date_utils::numberOfDaysInAMonth(date.year, date.month);
		}
	}
	else
		date.day--;

	return date;
}

stDate decreaseDateByXDays(stDate date, short days)
{
	while (days >= 1)
	{
		date = decreaseDateByOneDay(date);
		days--;
	}

	return date;
}

stDate decreaseDateByOneWeek(stDate date)
{
	return decreaseDateByXDays(date, 7);
}

stDate decreaseDateByXWeeks(stDate date, short weeks)
{
	while (weeks >= 1)
	{
		date = decreaseDateByOneWeek(date);
		weeks--;
	}

	return date;
}

stDate decreaseDateByOneMonth(stDate date)
{
	if (date.month == 1)
	{
		date.month = 12;
		date.year--;
	}

	else
		date.month--;

	// Case : 31/3/2022 -> 31/2/2022 is not valid so day become 28
	short monthDays = date_utils::numberOfDaysInAMonth(date.year, date.month);

	if (date.month == 2 && date_utils::isLeapYear(date.year))
		date.day = 29;

	else if (date.day > monthDays)
		date.day = monthDays;

	return date;
}

stDate decreaseDateByXMonths(stDate date, short months)
{
	while (months >= 1)
	{
		date = decreaseDateByOneMonth(date);
		months--;
	}

	return date;
}

stDate decreaseDateByOneYear(stDate date)
{
	date.year--;
	short monthDays = date_utils::numberOfDaysInAMonth(date.year, date.month);
	
	if (date.month == 2 && date.day == 28 && date_utils::isLeapYear(date.year))
		date.day = 29;

	else if (date.day > monthDays)
		date.day = monthDays;

	return date;
}

stDate decreaseDateByXYears(stDate date, short years)
{
	while (years >= 1)
	{
		date = decreaseDateByOneYear(date);
		years--;
	}

	return date;
}

stDate decreaseDateByXYearsFaster(stDate date, short years)
{
	date.year -= years;
	short monthDays = date_utils::numberOfDaysInAMonth(date.year, date.month);

	if (date.month == 2 && date.day == 28 && date_utils::isLeapYear(date.year))
		date.day = 29;

	else if (date.day > monthDays)
		date.day = monthDays;

	return date;
}

stDate decreaseDateByOneDecade(stDate date)
{
	return decreaseDateByXYearsFaster(date, 10);
}

stDate decreaseDateByXDecades(stDate date, short decades)
{
	while (decades >= 1)
	{
		date = decreaseDateByOneDecade(date);
		decades--;
	}

	return date;
}

stDate decreaseDateByXDecadesFaster(stDate date, short decades)
{
	date.year -= 10 * decades;
	short monthDays = date_utils::numberOfDaysInAMonth(date.year, date.month);

	if (date.day > monthDays)
		date.day = monthDays;

	return date;
}

stDate decreaseDateByOneCentury(stDate date)
{
	return decreaseDateByXYearsFaster(date, 100);
}

stDate decreaseDateByOneMellenium(stDate date)
{
	return decreaseDateByXYearsFaster(date, 1000);
}

int main()
{
	stDate date = date_utils::readFullDate();
	printf("\nDate after decrease operations:\n");

	date = decreaseDateByOneDay(date);
	printf("\n01 - Substracting one day is: %d/%d/%d\n", date.day, date.month, date.year);

	date = decreaseDateByXDays(date, 10);
	printf("02 - Substracting %d days is: %d/%d/%d\n", 10, date.day, date.month, date.year);

	date = decreaseDateByOneWeek(date);
	printf("03 - Substracting one week is: %d/%d/%d\n", date.day, date.month, date.year);

	date = decreaseDateByXWeeks(date, 10);
	printf("04 - Substracting %d weeks is: %d/%d/%d\n", 10, date.day, date.month, date.year);

	date = decreaseDateByOneMonth(date);
	printf("05 - Substracting one month is: %d/%d/%d\n", date.day, date.month, date.year);

	date = decreaseDateByXMonths(date, 10);
	printf("06 - Substracting %d months is: %d/%d/%d\n", 10, date.day, date.month, date.year);

	date = decreaseDateByOneYear(date);
	printf("07 - Substracting one year is: %d/%d/%d\n", date.day, date.month, date.year);

	date = decreaseDateByXYears(date, 10);
	printf("08 - Substracting %d years is: %d/%d/%d\n", 10, date.day, date.month, date.year);

	date = decreaseDateByXYearsFaster(date, 10);
	printf("09 - Substracting %d years (faster) is: %d/%d/%d\n", 10, date.day, date.month, date.year);

	date = decreaseDateByOneDecade(date);
	printf("10 - Substracting one decade is: %d/%d/%d\n", date.day, date.month, date.year);

	date = decreaseDateByXDecades(date, 10);
	printf("11 - Substracting %d decades is: %d/%d/%d\n", 10, date.day, date.month, date.year);

	date = decreaseDateByXDecadesFaster(date, 10);
	printf("12 - Substracting %d decades (faster) is: %d/%d/%d\n", 10, date.day, date.month, date.year);

	date = decreaseDateByOneCentury(date);
	printf("13 - Substracting one century is: %d/%d/%d\n", date.day, date.month, date.year);

	date = decreaseDateByOneMellenium(date);
	printf("14 - Substracting one mellenium is: %d/%d/%d\n\n\n", date.day, date.month, date.year);

	return 0;
}