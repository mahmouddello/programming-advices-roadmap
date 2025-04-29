#include <iostream>
#include "D:/MyCPP_Libs/headers/date_utils.h"

using namespace std;
using date_utils::stDate;

const enum enDateCompare { eBefore = -1, eEqual = 0, eAfter = 1 };

struct stPeriod
{
	stDate dateStart;
	stDate dateEnd;
};

enDateCompare compareDates(const stDate& date1, const stDate& date2)
{
	if (date_utils::isDateEqualsDate(date1, date2))
		return enDateCompare::eEqual;

	else if (date_utils::isDateBeforDate(date1, date2))
		return enDateCompare::eBefore;

	return enDateCompare::eAfter;
}

bool isDateWithinPeriod(stPeriod period, stDate date)
{
	if (compareDates(date, period.dateStart) == enDateCompare::eBefore)
		return false;

	if (compareDates(date, period.dateEnd) == enDateCompare::eAfter)
		return false;

	return true;
}

// programming advices
bool isDateInPeriod(stPeriod period, stDate date)
{
	// if not before the date, and not after, false || false = false -> !false = true
	return !(
		compareDates(date, period.dateStart) == enDateCompare::eBefore
		||
		compareDates(date, period.dateEnd) == enDateCompare::eAfter);
}

int main()
{
	stPeriod period1;
	stDate date;

	cout << "Period 1:" << endl;

	cout << "Enter Start Date:\n" << endl;
	period1.dateStart = date_utils::readFullDate();

	cout << "\nEnter End Date:" << endl;
	period1.dateEnd = date_utils::readFullDate();

	cout << "\nEnter a date:" << endl;
	date = date_utils::readFullDate();

	if (isDateWithinPeriod(period1, date))
	{
		cout << "\nYes, date within the provided period" << endl;
	}
	else
	{
		cout << "\nNo, date is not within the provided period" << endl;
	}

	if (isDateInPeriod(period1, date))
	{
		cout << "\nYes, date within the provided period" << endl;
	}
	else
	{
		cout << "\nNo, date is not within the provided period" << endl;
	}

	return 0;
}
