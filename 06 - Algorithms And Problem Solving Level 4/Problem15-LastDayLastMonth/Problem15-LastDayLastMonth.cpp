#include <iostream>
#include "D:/MyCPP_Libs/headers/date_utils.h"

using namespace std;
using date_utils::stDate;

// Delete these function after adding them to header file.
bool isLastDayInMonth(const stDate& date)
{
	return date.day == date_utils::numberOfDaysInAMonth(date.year, date.month);
}

bool isLastMonthInYear(const short& month)
{
	return month == 12;
}

void printResults(const stDate& date)
{
	if (date_utils::isLastDayInMonth(date))
		printf("Yes, day [%d] is the last day at month [%d]\n", date.day, date.month);
	else
		printf("No, day [%d] isn't the last day at month [%d]\n", date.day, date.month);

	if (date_utils::isLastMonthInYear(date.month))
		printf("Yes, month [%d] is the last day at year [%d]\n", date.month, date.year);
	else
		printf("No, month [%d] isn't the last day at year [%d]\n", date.month, date.year);
}

int main()
{
	stDate date = date_utils::readFullDate();

	printResults(date);

	return 0;
}