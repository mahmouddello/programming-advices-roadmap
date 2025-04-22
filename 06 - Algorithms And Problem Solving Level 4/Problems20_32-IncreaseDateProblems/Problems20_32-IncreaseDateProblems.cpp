#include <iostream>
#include "D:/MyCPP_Libs/headers/date_utils.h"

using date_utils::stDate;
using namespace std;

stDate increaseDateByXDays(stDate date, short days)
{
	while (days >= 1)
	{
		date = date_utils::increaseDateByOneDay(date);
		days--;
	}

	return date;
}

stDate increaseDateByOneWeek(stDate date)
{
	return increaseDateByXDays(date, 7);
}

stDate increaseDateByXWeeks(stDate date, short weeks)
{
	while (weeks >= 1)
	{
		date = increaseDateByOneWeek(date);
		weeks--;
	}

	return date;
}

stDate increaseDateByOneMonth(stDate date)
{
	if (date.month == 12)
	{
		date.month = 1;
		date.year++;
	}

	else
		date.month++;

	// if date is 31/1/2022 and we add 1 month, it's not true to make the date 31/2/2022 instead it should be 28/2/2022
	short maxDaysInMonth = date_utils::numberOfDaysInAMonth(date.year, date.month);
	if (date.day > maxDaysInMonth)
		date.day = maxDaysInMonth;

	return date;
}

stDate increaseDateByXMonths(stDate date, short months)
{
	while (months >= 1)
	{
		date = increaseDateByOneMonth(date);
		months--;
	}
	
	return date;
}

stDate increaseDateByOneYear(stDate date)
{
	date.year++;
	short maxDays = date_utils::numberOfDaysInAMonth(date.year, date.month);

	if (date.day > maxDays)
		date.day = maxDays;

	return date;
}

stDate increaseDateByXYears(stDate date, short years)
{
	while (years >= 1)
	{
		date = increaseDateByOneYear(date);
		years--;
	}

	return date;
}

stDate increaseDateByXYearsFaster(stDate date, short years)
{
	date.year += years;

	short maxDays = date_utils::numberOfDaysInAMonth(date.year, date.month);

	if (date.day > maxDays)
		date.day = maxDays;

	return date;

}

stDate increaseDateByOneDecade(stDate date)
{
	return increaseDateByXYearsFaster(date, 10);
}

stDate increaseDateByXDecads(stDate date, short decades)
{
	while (decades >= 1)
	{
		date = increaseDateByXYears(date, 10);
		decades--;
	}

	return date;
}

stDate increaseDateByXDecadsFaster(stDate date, short decades)
{
	date.year += decades * 10;

	short maxDays = date_utils::numberOfDaysInAMonth(date.year, date.month);

	if (date.day > maxDays)
		date.day = maxDays;

	return date;
}

stDate IncreaseDateByOneCentury(stDate date)
{
	return increaseDateByXYears(date, 100);
}

stDate IncreaseDateByOneMillennium(stDate date)
{
	return increaseDateByXYearsFaster(date, 1000);
}

int main()
{
	stDate date, newDate;
	
	date = date_utils::readFullDate();
	printf("\nDate after adding:\n\n");

	newDate = date_utils::increaseDateByOneDay(date);
	printf("01 - Adding %d day is: %d/%d/%d\n", 1, newDate.day, newDate.month, newDate.year);

	newDate = increaseDateByXDays(newDate, 10);
	printf("02 - Adding %d days is: %d/%d/%d\n", 10, newDate.day, newDate.month, newDate.year);

	newDate = increaseDateByOneWeek(newDate);
	printf("03 - Adding %d week is: %d/%d/%d\n", 1, newDate.day, newDate.month, newDate.year);

	newDate = increaseDateByXWeeks(newDate, 10);
	printf("04 - Adding %d weeks is: %d/%d/%d\n", 10, newDate.day, newDate.month, newDate.year);

	newDate = increaseDateByOneMonth(newDate);
	printf("05 - Adding %d month is: %d/%d/%d\n", 1, newDate.day, newDate.month, newDate.year);

	newDate = increaseDateByXMonths(newDate, 5);
	printf("06 - Adding %d months is: %d/%d/%d\n", 5, newDate.day, newDate.month, newDate.year);

	newDate = increaseDateByOneYear(newDate);
	printf("07 - Adding %d year is: %d/%d/%d\n", 1, newDate.day, newDate.month, newDate.year);

	newDate = increaseDateByXYears(newDate, 10);
	printf("08 - Adding %d years is: %d/%d/%d\n", 10, newDate.day, newDate.month, newDate.year);

	newDate = increaseDateByXYearsFaster(newDate, 10);
	printf("09 - Adding %d years (faster) is: %d/%d/%d\n", 10, newDate.day, newDate.month, newDate.year);	
	
	newDate = increaseDateByOneDecade(newDate);
	printf("10 - Adding %d decade is: %d/%d/%d\n", 1, newDate.day, newDate.month, newDate.year);

	newDate = increaseDateByXDecads(newDate, 10);
	printf("11 - Adding %d decades is: %d/%d/%d\n", 10, newDate.day, newDate.month, newDate.year);

	newDate = increaseDateByXDecadsFaster(newDate, 10);
	printf("12 - Adding %d decades (faster) is: %d/%d/%d\n", 10, newDate.day, newDate.month, newDate.year);

	newDate = IncreaseDateByOneCentury(newDate);
	printf("13 - Adding %d century is: %d/%d/%d\n", 1, newDate.day, newDate.month, newDate.year);

	newDate = IncreaseDateByOneMillennium(newDate);
	printf("14 - Adding %d mellenium is: %d/%d/%d\n", 1, newDate.day, newDate.month, newDate.year);

	return 0;
}