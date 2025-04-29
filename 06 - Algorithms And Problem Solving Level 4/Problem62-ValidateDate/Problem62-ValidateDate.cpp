#include <iostream>
#include "D:/MyCPP_Libs/headers/date_utils.h"

using namespace std;
using date_utils::stDate;

bool validateDate(const stDate& date)
{
	return date.month < 1 || date.month > 12 ? false : date.day <= date_utils::numberOfDaysInAMonth(date.year, date.month);
}

int main()
{

	stDate date = date_utils::readFullDate();

	if (validateDate(date))
		cout << "\nYes, date is a valid date" << endl;
	else
		cout << "\nNo, date is NOT a valid date" << endl;

	return 0;
}