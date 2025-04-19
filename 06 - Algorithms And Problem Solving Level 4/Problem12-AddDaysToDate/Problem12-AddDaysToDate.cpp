#include <iostream>
#include "D:/MyCPP_Libs/headers/date_utils.h"
#include "D:/MyCPP_Libs/headers/input_utils.h"

using namespace std;
using date_utils::stDate;

// stDate is inside date_utils.h

stDate readFullDate()
{
	stDate date;

	date.day = date_utils::readDay();
	date.month = date_utils::readMonth();
	date.year = date_utils::readYear();

	return date;
}

stDate dateAddDays(short days, stDate date)
{
	
	// assume days from the beginning of the year: 300, and days to add: 150
	// we go back to the beginning of the year, and add 450 days and see where we reach
	short remainingDays = date_utils::numberOfDaysFromBeginningOfTheYear(date.year, date.month, date.day);
	remainingDays += days;

	short monthDays = 0;
	date.month = 1;

	while (true)
	{
		monthDays = date_utils::numberOfDaysInAMonth(date.year, date.month);

		if (remainingDays > monthDays)
		{
			remainingDays -= monthDays;
			date.month++; // increment month by 1 to move to next month

			if (date.month > 12)
			{
				date.year++;
				date.month = 1;
				// if month reachs 13 this means we passed a year, increment year by 1 and reset month to 1
			}
		}
		else
		{
			// here it didn't pass the first condition, so the remaining days are less than a monthDays
			date.day = remainingDays;
			break;
		}
	}

	return date;
}

// optimized solution
stDate dateAddDaysV2(short days, stDate Date) {

	short reminingDays = days + date_utils::numberOfDaysFromBeginningOfTheYear(Date.day, Date.month, Date.year);

	while (reminingDays > date_utils::getNumberOfDays(Date.year))
	{
		reminingDays -= date_utils::getNumberOfDays(Date.year);
		Date.year++;
	}

	Date = date_utils::getDateFromDayOrderInYear(reminingDays, Date.year);

	return Date;
}

int main()
{
	stDate date = readFullDate();
	short days = input_utils::readPositiveNumber("How many days do you want to add? ");

	date = dateAddDaysV2(days, date);

	cout << "\nDate after adding [" << days << "] days is: ";
	printf("%d/%d/%d\n", date.day, date.month, date.year);

	return 0;
}