#include <iostream>
#include "D:/MyCPP_Libs/headers/date_utils.h"

using namespace std;
using date_utils::stDate;

const enum enDateCompare { eBefore = -1, eEqual = 0, eAfter = 1 };

enDateCompare compareDates(const stDate& date1, const stDate& date2)
{
	if (date_utils::isDateEqualsDate(date1, date2))
		return enDateCompare::eEqual;

	else if (date_utils::isDateBeforDate(date1, date2))
		return enDateCompare::eBefore;

	return enDateCompare::eAfter;
}

struct stPeriod
{
	stDate dateStart;
	stDate dateEnd;
};

bool isDateInPeriod(stDate date, stPeriod period)
{
	// if not before the date, and not after, false || false = false -> !false = true
	return !(
		compareDates(date, period.dateStart) == enDateCompare::eBefore
		||
		compareDates(date, period.dateEnd) == enDateCompare::eAfter);
}

bool isPeriodsOverlap(stPeriod period1, stPeriod period2)
{
	if (compareDates(period2.dateEnd, period1.dateStart) == enDateCompare::eBefore)
		return false;

	if (compareDates(period2.dateStart, period1.dateEnd) == enDateCompare::eAfter)
		return false;

	return true;

}

short periodLengthInDays(stPeriod period, bool includeEndDay = false)
{
	return date_utils::differenceInDays(period.dateStart, period.dateEnd, includeEndDay);
}

// programming advices (I couldn't solve it)
int CountOverlapDays(stPeriod Period1, stPeriod Period2)
{
	int Period1Length = periodLengthInDays(Period1, true);
	int Period2Length = periodLengthInDays(Period2, true);
	int OverlapDays = 0;

	if (!isPeriodsOverlap(Period1, Period2))
		return 0;

	if (Period1Length < Period2Length)
	{
		while (date_utils::isDateBeforDate(Period1.dateStart,Period1.dateEnd))
		{
			if (isDateInPeriod(Period1.dateStart, Period2))
				OverlapDays++;
			Period1.dateStart = date_utils::increaseDateByOneDay(Period1.dateStart);
		}
	}
	else
	{
		while (isDateBeforDate(Period2.dateStart, Period2.dateEnd))
		{
			if (isDateInPeriod(Period2.dateStart, Period1))
				OverlapDays++;
			Period2.dateStart = date_utils::increaseDateByOneDay(Period2.dateStart);
		}
	}
	return OverlapDays;
}

// optimized (from GPT and comments)
int countOverlapDaysV2(stPeriod p1, stPeriod p2)
{
	if (!isPeriodsOverlap(p1, p2))
		return 0;

	stPeriod newPeriod;
	newPeriod.dateStart = (compareDates(p1.dateStart, p2.dateStart) == eAfter) ? p1.dateStart : p2.dateStart;
	newPeriod.dateEnd = (compareDates(p1.dateEnd, p2.dateEnd) == eBefore) ? p1.dateEnd : p2.dateEnd;
	
	return periodLengthInDays(newPeriod);
}

int main()
{
	stPeriod period1, period2;

	cout << "Period 1:" << endl;

	cout << "Enter Start Date:\n" << endl;
	period1.dateStart = date_utils::readFullDate();

	cout << "\nEnter End Date:" << endl;
	period1.dateEnd = date_utils::readFullDate();

	cout << "\nPeriod 2:" << endl;

	cout << "Enter Start Date:\n" << endl;
	period2.dateStart = date_utils::readFullDate();

	cout << "\nEnter End Date:" << endl;
	period2.dateEnd = date_utils::readFullDate();

	int days = CountOverlapDays(period1, period2);
	int days2 = countOverlapDaysV2(period1, period2);

	if (days)
		cout << "\nDays count is: " << days << endl;
	else
		cout << "\nNo overlapped days" << endl;
	
	if (days)
		cout << "\nDays count is: " << days2 << endl;
	else
		cout << "\nNo overlapped days" << endl;

	return 0;
}