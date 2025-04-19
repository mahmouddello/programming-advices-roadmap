#include <iostream>
#include "D:/MyCPP_Libs/headers/date_utils.h"

using namespace std;
using date_utils::stDate;

// Programming Advices
bool isDate1BeforeDate2(stDate date1, stDate date2)
{
	return (date1.year < date2.year) ? true : ((date1.year == date2.year) ? (date1.month < date2.month ? true : (date1.month ==date2.month ? date1.day < date2.day : false)) : false);
}

// From Comments (Much easier to understand)
bool isDateBeforDate(stDate date1, stDate date2)
{
	if (date1.year != date2.year)
		return date1.year < date2.year;

	if (date1.month != date2.month)
		return date1.month < date2.month;

	return date1.day < date2.day;
}

int main()
{
	stDate date1 = date_utils::readFullDate();
	stDate date2 = date_utils::readFullDate();

	if (isDateBeforDate(date1, date2))
		cout << "\nYes, Date 1 is less than Date 2" << endl;
	else
		cout << "\nNO, Date 1 is greater than Date 2" << endl;

	return 0;
}