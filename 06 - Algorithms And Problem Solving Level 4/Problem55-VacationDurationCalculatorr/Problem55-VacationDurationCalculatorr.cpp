#include <iostream>
#include "../mylibs/headers/date_utils.h"

using namespace std;
using date_utils::stDate;

short readVacationDays()
{
	short days = 0;
	cout << "Please enter vacation days: ";
	cin >> days;

	return days;
}

stDate calculateVacationDuration(const stDate& startDate, short vacationDays)
{
	stDate endDate = startDate;

	while (vacationDays >= 1)
	{
		if (date_utils::isBusinessDay(date_utils::dayOfWeekOrder(endDate)))
			vacationDays--;

		endDate = date_utils::increaseDateByOneDay(endDate);
	}

	return endDate;
}

int main()
{

	cout << "Vacation start:\n" << endl;
	stDate vacationStartDate = date_utils::readFullDate();

	short vacationDays = readVacationDays();
	stDate vacationEndDate = calculateVacationDuration(vacationStartDate, vacationDays);

	cout << "\n\nReturn date: ";
	cout << date_utils::dayShortName(date_utils::dayOfWeekOrder(vacationEndDate)) << ", ";
	cout << vacationEndDate.day << "/" << vacationEndDate.month << "/" << vacationEndDate.year << endl;

	return 0;
}