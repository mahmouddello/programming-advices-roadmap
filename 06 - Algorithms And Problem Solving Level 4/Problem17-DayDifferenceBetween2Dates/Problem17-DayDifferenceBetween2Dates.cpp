#include <iostream>
#include "../mylibs/headers/date_utils.h"

using namespace std;
using date_utils::stDate;

// My solution (too long, hard to understand)
short differenceInDaysV2(stDate date1, stDate date2, bool includeEndDay = false)
{

	short date1Days = 0, date2Days = 0;
	short daysPassed = 0, daysToYearEnd = 0;
	short totalDays = 0;
	
	if (date_utils::isDateBeforDate(date1, date2))
	{
		if (date1.year == date2.year)
		{
			date1Days = date_utils::numberOfDaysFromBeginningOfTheYear(date1.year, date1.month, date1.day);
			date2Days = date_utils::numberOfDaysFromBeginningOfTheYear(date2.year, date2.month, date2.day);

			if (includeEndDay)
				date2Days++;

			return date2Days - date1Days;
		}

		else
		{
			while (date1.year < date2.year)
			{
				date1Days = date_utils::numberOfDaysFromBeginningOfTheYear(date1.year, date1.month, date1.day);
				daysToYearEnd = date_utils::getNumberOfDays(date1.year) - date1Days + 1;

				totalDays += daysToYearEnd;

				date1 = date_utils::dateAddDaysV2(daysToYearEnd, date1);
			}

			date1Days = date_utils::numberOfDaysFromBeginningOfTheYear(date1.year, date1.month, date1.day);
			date2Days = date_utils::numberOfDaysFromBeginningOfTheYear(date2.year, date2.month, date2.day);

			if (includeEndDay)
				date2Days++;

			return totalDays + (date2Days - date1Days);

		}
	}

	else if (date_utils::isDateEqualsDate(date1, date2))
		return includeEndDay ? 1 : 0;

	return -1;
}

// Programming Advices
int differenceInDays(stDate date1, stDate date2, bool includeEndDay = false)
{
	int days = 0;

	while (date_utils::isDateBeforDate(date1, date2))
	{
		days++;
		date1 = date_utils::increaseDateByOneDay(date1);
	}

	return includeEndDay ? ++days : days;
}

int main()
{
	stDate date1 = date_utils::readFullDate();
	stDate date2 = date_utils::readFullDate();

	cout << "Difference is: " << differenceInDaysV2(date1, date2) << endl;
	cout << "Difference is (End day included): " << differenceInDaysV2(date1, date2, true) << endl;

	return 0;
}