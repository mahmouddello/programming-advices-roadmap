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

bool isDateOverlap(stPeriod period1, stPeriod period2)
{
	if (date_utils::isDateBeforDate(period1.dateStart, period2.dateEnd))
		if (date_utils::isDateAfterDate(period1.dateEnd, period2.dateStart))
			return true;
	return false;
}

// Programming Advices
bool isPeriodsOverlap(stPeriod period1, stPeriod period2)
{
	if (compareDates(period2.dateEnd, period1.dateStart) == enDateCompare::eBefore)
		return false;
	
	if (compareDates(period2.dateStart, period1.dateEnd) == enDateCompare::eAfter)
		return false;

	return true;

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

	if (isDateOverlap(period1, period2))
		cout << "\nYes periods overlap" << endl;
	else
		cout << "\nNo periods doesn't overlap" << endl;

	if (isPeriodsOverlap(period1, period2))
		cout << "\nYes periods overlap" << endl;
	else
		cout << "\nNo periods doesn't overlap" << endl;

	return 0;
}