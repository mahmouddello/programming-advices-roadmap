#include <iostream>
#include "D:/MyCPP_Libs/headers/date_utils.h"

using namespace std;
using date_utils::stDate;

bool isDateEqualsDate(stDate date1, stDate date2)
{
	if (date1.year != date2.year)
		return false;

	if (date1.month != date2.month)
		return false;

	return date1.day == date2.day;
}

int main()
{
	stDate date1 = date_utils::readFullDate();
	stDate date2 = date_utils::readFullDate();

	if (date_utils::isDateEqualsDate(date1, date2))
		cout << "\nYes, Date 1 equals Date 2" << endl;
	else
		cout << "\nNo, Date 1 doesn't equals Date 2" << endl;

	return 0;
}