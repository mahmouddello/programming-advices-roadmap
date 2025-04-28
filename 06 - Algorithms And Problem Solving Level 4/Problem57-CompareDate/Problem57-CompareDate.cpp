#include <iostream>
#include "D:/MyCPP_Libs/headers/date_utils.h"

using namespace std;
using date_utils::stDate;

const enum enDateCompare {eBefore = -1, eEqual = 0, eAfter = 1};

enDateCompare compareDates(const stDate& date1, const stDate& date2)
{
	if (date_utils::isDateEqualsDate(date1, date2))
		return enDateCompare::eEqual;

	else if (date_utils::isDateBeforDate(date1, date2))
		return enDateCompare::eBefore;

	return enDateCompare::eAfter;
}

int main()
{
	cout << "Date 1:" << endl;
	stDate date1 = date_utils::readFullDate();

	cout << "\nDate 2:" << endl;
	stDate date2 = date_utils::readFullDate();

	cout << "\nCompare result is: " << compareDates(date1, date2) << endl;

	return 0;
}