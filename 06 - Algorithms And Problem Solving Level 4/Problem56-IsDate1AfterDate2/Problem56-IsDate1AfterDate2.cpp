#include <iostream>
#include "../mylibs/headers/date_utils.h"

using namespace std;
using date_utils::stDate;

bool isDateAfterDate(stDate date1, stDate date2)
{
	return !(date_utils::isDateBeforDate(date1, date2));
}

int main()
{
	cout << "Date 1:" << endl;
	stDate date1 = date_utils::readFullDate();

	cout << "\nDate 2:" << endl;
	stDate date2 = date_utils::readFullDate();

	if (isDateAfterDate(date1, date2))
		cout << "Yes, Date 1 is after Date 2" << endl;
	else
		cout << "No, Date 1 is not after Date 2" << endl;

	return 0;
}