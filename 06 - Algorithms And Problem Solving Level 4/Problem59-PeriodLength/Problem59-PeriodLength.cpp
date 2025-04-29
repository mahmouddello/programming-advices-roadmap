#include <iostream>
#include "D:/MyCPP_Libs/headers/date_utils.h"

using namespace std;
using date_utils::stDate;

struct stPeriod
{
	stDate dateStart;
	stDate dateEnd;
};

short periodLengthInDays(stPeriod period, bool includeEndDay = false)
{
	return date_utils::differenceInDays(period.dateStart, period.dateEnd, includeEndDay);
}

int main()
{
	stPeriod period1;

	cout << "Period 1:" << endl;

	cout << "Enter Start Date:\n" << endl;
	period1.dateStart = date_utils::readFullDate();

	cout << "\nEnter End Date:" << endl;
	period1.dateEnd = date_utils::readFullDate();

	cout << "\nPeriod Length is: ";
	cout << periodLengthInDays(period1) << endl;

	cout << "Period Length is (Including end day): ";
	cout << periodLengthInDays(period1, true) << endl;

	return 0;
}