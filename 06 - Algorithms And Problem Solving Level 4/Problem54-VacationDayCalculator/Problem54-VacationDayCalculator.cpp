#include <iostream>
#include "../mylibs/headers/date_utils.h"

using namespace std;
using date_utils::stDate;

void dispalyVacationInfo(const stDate& start, const stDate& end)
{
	string startDay = date_utils::dayShortName(date_utils::dayOfWeekOrder(start));
	string endDay = date_utils::dayShortName(date_utils::dayOfWeekOrder(end));

	printf("Vacation from: %s, %d/%d/%d\n", startDay.c_str(), start.day, start.month, start.year);
	printf("Vacation to: %s, %d/%d/%d\n", endDay.c_str(), end.day, end.month, end.year);
}

short actualVacationDaysCount(stDate start, const stDate& end)
{
	
	short counter = 0;

	while (date_utils::isDateBeforDate(start, end))
	{
		// good but there is simpler one
		//if (!(date_utils::isWeekend(date_utils::dayOfWeekOrder(start))))
		//	counter++;

		if (date_utils::isBusinessDay(date_utils::dayOfWeekOrder(start)))
			counter++;

		// start.day++;  use increase by one day to ensure errors when incrementing days
		start = date_utils::increaseDateByOneDay(start);
	}

	return counter;
}

int main() {

	cout << "Vacation start:\n" << endl;
	stDate vacationStart = date_utils::readFullDate();

	cout << "Vacation ends:\n" << endl;
	stDate vacationEnd = date_utils::readFullDate();

	dispalyVacationInfo(vacationStart, vacationEnd);

	cout << "\n\nActual vacation days is: ";
	cout << actualVacationDaysCount(vacationStart, vacationEnd) << endl;

	return 0;
}